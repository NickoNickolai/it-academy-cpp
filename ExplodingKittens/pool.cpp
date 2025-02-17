#include "pool.h"
#include "human.h"
#include "robot.h"
#include "logger.h"

#define HAND_SIZE 5

Pool::Pool()
{
    _currPlayerIndex = 0;
    _winner = nullptr;
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
    default:
        break;
    }
    _players.push_back(player);
    connect(player, &Player::signalSendCard, this, &Pool::signalSendCard);
    connect(player, &Player::signalSendNope, this, &Pool::signalSendNope);
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
