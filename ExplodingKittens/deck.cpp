#include "deck.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "logger.h"

Deck::Deck()
{
    std::srand(std::time(nullptr));
}

void Deck::initBase()
{
    setupBase();
    shuffle();
#ifdef USE_VERBOSE_DEBUG
    Logger::log("Deck after base setup:");
    print();
#endif
}

void Deck::initExtra(int extraCards)
{
    addExtraCards(extraCards);
    shuffle();
#ifdef USE_VERBOSE_DEBUG
    Logger::log("Deck after extra setup:");
    print();
#endif
}

void Deck::addCard(const Card &card)
{
    _deck.push_back(card);
}

Card Deck::takeCard()
{
    auto card = _deck.front();
    _deck.pop_front();
    return card;
}

void Deck::shuffle()
{
#ifdef USE_VERBOSE_DEBUG
    Logger::log("Shuffling deck");
#endif
    for(decltype(size()) k = 0; k < size(); ++k)
    {
        int i = rand() % size();
        int j = rand() % size();
        std::swap(_deck[i], _deck[j]);
    }
    emit signalShuffled();
}

void Deck::print()
{
    std::cout << "Deck [" << size() << "]: ";
    for(decltype(size()) i = 0; i < size(); ++i)
    {
        std::cout << _deck[i] << "#" << i << " ";
    }
    std::cout << std::endl;
}

void Deck::setupBase()
{
    _deck.clear();

    for(int i = 0; i < 4; ++i)
    {
        addCard(Card(CardType::ATTACK));
        addCard(Card(CardType::SHUFFLE));
        addCard(Card(CardType::SKIP));
        addCard(Card(CardType::FAVOR));
    }
    for(int i = 0; i < 5; ++i)
    {
        addCard(Card(CardType::FUTURE));
        addCard(Card(CardType::NOPE));
    }
    for(int i = 0; i < 4 * 4; ++i)
    {
        addCard(Card(CardType::CAT));
    }
}

void Deck::addExtraCards(int playersNumber)
{
    for(int i = 0; i < playersNumber - 1; ++i)
    {
        addCard(Card(CardType::EXPLODE));
    }
    addCard(Card(CardType::DEFUSE));
}

void Deck::slotRequestCard()
{
    emit signalSendCard(takeCard());
}
