#include "human.h"
#include <iostream>

Human::Human(std::string name)
    : Player(PlayerType::HUMAN, name)
{}

void Human::reqCard(PlayerState state)
{
    if(state.exploded)
    {
        std::cout << "YOU MUST DEFUSE EXPLODING CARD!" << std::endl;
    }
    printHand();
    printFuture();
    std::string buf = std::to_string(_hand.size());
    do
    {
        if(buf == "p")
        {
            emit signalSendCard(Card(CardType::PASS));
            return;
        }
        size_t n = _hand.size();
        try
        {
            n = std::stoul(buf);
        }
        catch(const std::exception &e)
        {
            std::cout << "Exception: invalid input" << std::endl;
        }
        if(n < _hand.size())
        {
            auto it = _hand.begin();
            std::advance(it, n);
            auto card = *it;
            _hand.erase(it);
            emit signalSendCard(card);
            return;
        }
        std::cout << "Enter card number or 'p' to pass: ";
    }
    while(std::cin >> buf);
}

void Human::reqNope(PlayerState)
{
    auto it = std::find_if(_hand.begin(), _hand.end(), [](const Card & card)
    {
        return card.type() == CardType::NOPE;
    });
    if(it != _hand.end())
    {
        printHand();
        printFuture();
        std::cout << "Do you want deny opponent card? [y, n]: ";
        char ch;
        std::cin >> ch;
        if(std::tolower(ch) == 'y')
        {
            _hand.erase(it);
            emit signalSendNope(true);
            return;
        }
    }
    emit signalSendNope(false);
}

void Human::reqFavor()
{
    auto card = Card(CardType::PASS);
    if(!_hand.empty())
    {
        printHand();
        size_t n = _hand.size();
        do
        {
            if(n < _hand.size())
            {
                auto it = _hand.begin();
                std::advance(it, n);
                card = *it;
                _hand.erase(it);
                break;
            }
            else
            {
                std::cout << "Choose card number to take away: ";
            }
        }
        while(std::cin >> n);
    }
    emit signalSendFavor(card);
}
