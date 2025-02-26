#include "robot.h"
#include <algorithm>
#include <thread>

#define DELAY 250

Robot::Robot()
    : Robot(std::string("Robot-") + std::to_string(_uid + 1))
{}

Robot::Robot(std::string name)
    : Player(PlayerType::ROBOT, name)
{
    ++_uid;
}

Robot::~Robot()
{
    --_uid;
}

void Robot::reqCard(PlayerState state)
{
#ifdef USE_DEBUG
    printHand();
    printFuture();
#endif
    std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));
    if(_hand.size())
    {
        if(state.exploded)
        {
            auto it = std::find_if(_hand.begin(), _hand.end(), [](const Card & card)
            {
                return card.type() == CardType::DEFUSE;
            });
            if(it != _hand.end())
            {
                auto card = *it;
                _hand.erase(it);
                emit signalSendCard(card);
                return;
            }
        }
        else
        {
            // Тактика защиты от EXPLODE
            if(!_future.empty() && _future.front().type() == CardType::EXPLODE)
            {
                {
                    auto it = std::find_if(_hand.begin(), _hand.end(), [](const Card & card)
                    {
                        return card.type() == CardType::ATTACK;
                    });
                    if(it != _hand.end())
                    {
                        auto card = *it;
                        _hand.erase(it);
                        emit signalSendCard(card);
                        return;
                    }
                }
                {
                    auto it = std::find_if(_hand.begin(), _hand.end(), [](const Card & card)
                    {
                        return card.type() == CardType::SKIP;
                    });
                    if(it != _hand.end())
                    {
                        auto card = *it;
                        _hand.erase(it);
                        emit signalSendCard(card);
                        return;
                    }
                }
                {
                    auto it = std::find_if(_hand.begin(), _hand.end(), [](const Card & card)
                    {
                        return card.type() == CardType::SHUFFLE;
                    });
                    if(it != _hand.end())
                    {
                        auto card = *it;
                        _hand.erase(it);
                        emit signalSendCard(card);
                        return;
                    }
                }
            }
            auto card = _hand.back();
            if(card.type() != CardType::DEFUSE && card.type() != CardType::NOPE)
            {
                _hand.pop_back();
                emit signalSendCard(card);
                return;
            }
        }
    }
    emit signalSendCard(Card(CardType::PASS));
}

void Robot::reqNope(PlayerState state)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));
    if(_hand.size())
    {
        if(state.attacked || state.skipped || state.shuffled)
        {
            auto it = std::find_if(_hand.begin(), _hand.end(), [](const Card & card)
            {
                return card.type() == CardType::NOPE;
            });
            if(it != _hand.end())
            {
                _hand.erase(it);
                emit signalSendNope(true);
                return;
            }
        }
    }
    emit signalSendNope(false);
}

void Robot::reqFavor()
{
    if(_hand.empty())
    {
        emit signalSendFavor(Card(CardType::PASS));
        return;
    }
    auto card = _hand.back();
    _hand.pop_back();
    emit signalSendFavor(card);
}
