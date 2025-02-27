#include "pool.h"
#include "human.h"
#include "robot.h"
#include "remoteplayer.h"
#include "logger.h"

#include <QTimer>
#include <QEventLoop>
#include "settings.h"
#include "netstructs.h"

#define HAND_SIZE 5
#define CONNECTION_TIMEOUT 30000

Pool::Pool()
{
    _currPlayerIndex = 0;
    _winner = nullptr;
    _server = new TcpServer(Settings::port());
}

Pool::~Pool()
{
    delete _server;
}

void Pool::addPlayer(PlayerType type, const std::string &name)
{
    Player *player = nullptr;
    switch(type)
    {
    case PlayerType::HUMAN:
        player = new Human(name);
        break;
    case PlayerType::ROBOT:
        player = new Robot();
        break;
    case PlayerType::REMOTE_PLAYER:
    {
        // Получение имени игрока-клиента
        std::string clientName = "Remote";
        connect(_server, &TcpServer::signalRecvDataFromClient, this, [&clientName](QByteArray data)
        {
            auto msg = reinterpret_cast<NetworkPacket *>(data.data());
            clientName = std::string(msg->name);
        });

        // Ожидание подключения клиента
        QEventLoop loop;
        QTimer timer;
        timer.setSingleShot(true);
        connect(_server, &TcpServer::signalRecvDataFromClient, &loop, &QEventLoop::quit);
        connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);

        timer.start(CONNECTION_TIMEOUT);
        loop.exec();

        // Имя игрока-клиента получено, отключить получение
        disconnect(_server, &TcpServer::signalRecvDataFromClient, 0, 0);

        if(timer.isActive())
        {
            player = new RemotePlayer(clientName);

            // Отправка/получение сетевых пакетов для игрока-клиента
            connect(player, &Player::signalSendNetworkData, this, &Pool::slotSendNetworkData);
            connect(_server, &TcpServer::signalRecvDataFromClient, this, &Pool::slotRecvNetworkData);
        }
        else
        {
            Logger::str("Client doesn't respond, timeout");
            return;
        }
        break;
    }
    default:
        return;
    }
    _players.push_back(player);
    connect(player, &Player::signalSendCard, this, &Pool::signalSendCard);
    connect(player, &Player::signalSendNope, this, &Pool::signalSendNope);
    connect(player, &Player::signalSendFavor, this, &Pool::signalSendFavor);
}

void Pool::clear()
{
    for(const auto &player : _players)
    {
        delete player;
    }
    _players.clear();
}

void Pool::switchToNextPlayer()
{
    do
    {
        _currPlayerIndex = (_currPlayerIndex + 1) % _players.size();
    }
    while(!_players[_currPlayerIndex]->valid());
#ifdef USE_VERBOSE_DEBUG
    Logger::log("Player switched to " + _players[_currPlayerIndex]->name());
#endif
}

void Pool::switchToPrevPlayer()
{
    do
    {
        _currPlayerIndex = (_currPlayerIndex + _players.size() - 1) % _players.size();
    }
    while(!_players[_currPlayerIndex]->valid());
#ifdef USE_VERBOSE_DEBUG
    Logger::log("Player switched to " + _players[_currPlayerIndex]->name());
#endif
}

void Pool::addCardToPlayer(int n, Card card)
{
    _players[n]->addCard(card);
}

void Pool::slotShuffled()
{
    for(const auto &player : _players)
    {
        player->resetFuture();
    }
}

void Pool::slotPopFuture()
{
    for(const auto &player : _players)
    {
        player->popFuture();
    }
}

void Pool::slotSendNetworkData(QByteArray data)
{
    _server->slotSendDataToClient(data);
}

void Pool::slotRecvNetworkData(QByteArray data)
{
    auto msg = reinterpret_cast<NetworkPacket *>(data.data());

    switch(msg->type)
    {
    case PacketType::PLAY_CARD:
    {
        emit signalSendCard(msg->card);
        break;
    }
    case PacketType::NOPE_CARD:
    {
        emit signalSendNope(msg->nope);
        break;
    }
    case PacketType::FAVOR_CARD:
    {
        emit signalSendFavor(msg->card);
        break;
    }
    default:
        Logger::str("Received unknown packet from client");
        break;
    }
}

void Pool::defeatPlayer()
{
    _players[_currPlayerIndex]->setValid(false);
}

void Pool::setupHands()
{
    for(decltype(size()) n = 0; n < size(); ++n)
    {
        _players[n]->clearHand();
        _players[n]->addCard(Card(CardType::DEFUSE));
        for(int i = 0; i < HAND_SIZE; ++i)
        {
            emit signalRequestCard(n);
        }
    }
}

void Pool::print() const
{
    for(const auto &player : _players)
    {
        player->printHand();
        player->printFuture();
    }
}

Player *Pool::winner()
{
    int validPlayersCount = 0;
    for(const auto &player : _players)
    {
        if(player->valid())
        {
            ++validPlayersCount;
            _winner = player;
        }
    }
    if(validPlayersCount > 1)
    {
        _winner = nullptr;
    }
    return _winner;
}
