#include "remotegame.h"
#include "netstructs.h"
#include <QTimer>
#include <QEventLoop>
#include "settings.h"
#include "logger.h"

#define SETTINGS_FNAME "config.ini"

RemoteGame::RemoteGame(const std::string &name)
{
    _player = new Human(name);
    _client = new TcpClient(QHostAddress(Settings::host()), Settings::port());

    connect(_player, &Player::signalSendCard, this, [this](Card card)
    {
        NetworkPacket packet;
        packet.type = PacketType::PLAY_CARD;
        packet.card = card;
        slotSendNetworkData(toQByteArray(packet));
    });
    connect(_player, &Player::signalSendNope, this, [this](bool nope)
    {
        NetworkPacket packet;
        packet.type = PacketType::NOPE_CARD;
        packet.nope = nope;
        slotSendNetworkData(toQByteArray(packet));
    });
    connect(_player, &Player::signalSendFavor, this, [this](Card card)
    {
        NetworkPacket packet;
        packet.type = PacketType::FAVOR_CARD;
        packet.card = card;
        slotSendNetworkData(toQByteArray(packet));
    });
    connect(_client, &TcpClient::signalRecvDataFromServer, this, &RemoteGame::slotRecvNetworkData);

    // Отправка серверу имени игрока - признак готовности к игре
    NetworkPacket packet;
    packet.type = PacketType::PLAYER_NAME;
    strncpy(packet.name, name.data(), name.size());
    slotSendNetworkData(toQByteArray(packet));
}

RemoteGame::~RemoteGame()
{
    delete _client;
}

void RemoteGame::newGame()
{
    QEventLoop loop;
    loop.exec();
}

void RemoteGame::slotSendNetworkData(QByteArray data)
{
    _client->slotSendDataToServer(data);
}

void RemoteGame::slotRecvNetworkData(QByteArray data)
{
    auto msg = reinterpret_cast<NetworkPacket *>(data.data());

    switch(msg->type)
    {
    case PacketType::REQUEST_CARD:
    {
        PlayerState state;
        state.exploded = msg->exploded;
        _player->reqCard(state);
        break;
    }
    case PacketType::REQUEST_NOPE:
    {
        PlayerState state;
        _player->reqNope(state);
        break;
    }
    case PacketType::REQUEST_FAVOR:
    {
        _player->reqFavor();
        break;
    }
    case PacketType::ADD_FUTURE:
    {
        _player->addFuture(msg->card);
        break;
    }
    case PacketType::POP_FUTURE:
    {
        _player->popFuture();
        break;
    }
    case PacketType::RESET_FUTURE:
    {
        _player->resetFuture();
        break;
    }
    case PacketType::DECK_CARD:
    {
        _player->addCard(msg->card);
        break;
    }
    case PacketType::GAME_MESSAGE:
    {
        Logger::str(msg->message);
        break;
    }
    default:
        break;
    }
#ifdef USE_DEBUG
    Logger::str("Waiting for server player action...");
#endif
}
