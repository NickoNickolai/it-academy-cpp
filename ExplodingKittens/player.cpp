#include "player.h"
#include <iostream>

Player::Player(PlayerType type, std::string name)
    : _valid(true), _type(type), _name(name)
{}

void Player::addCard(Card card)
{
    _hand.push_back(card);
}

void Player::printHand() const
{
    std::cout << name() << "'s hand: ";
    if(_hand.empty())
    {
        std::cout << "empty" << std::endl;
        return;
    }
    for(decltype(_hand.size()) i = 0; i < _hand.size(); ++i)
    {
        std::cout << _hand[i] << "#" << i << " ";
    }
    std::cout << std::endl;
}

void Player::printFuture() const
{
    if(!_future.empty())
    {
        std::cout << name() << "'s future: ";
        for(decltype(_future.size()) i = 0; i < _future.size(); ++i)
        {
            std::cout << _future[i] << "#" << i << " ";
        }
        std::cout << std::endl;
    }
}

void Player::addFuture(const Card &card)
{
    _future.push_back(card);
}

void Player::popFuture()
{
    if(!_future.empty())
    {
        _future.pop_front();
    }
}

void Player::resetFuture()
{
    _future.clear();
}
