#ifndef DECK_H
#define DECK_H

#include <QObject>
#include <deque>
#include "card.h"

class Deck : public QObject
{
    Q_OBJECT
public:
    Deck();

    // Поэтапная инициализация колоды
    void initBase();
    void initExtra(int extraCards);

    // Добавление карты в колоду
    void addCard(const Card &card);

    // Взятие карты из колоды
    Card takeCard();

    // Перетасовка колоды
    void shuffle();

    // Вывод содержимого колоды в консоль
    void print();

    // Получение числа карт в колоде
    auto size() { return _deck.size(); }

public:
    auto &operator[](int n) { return _deck[n]; }

signals:
    // Выдача карты в игру
    void signalSendCard(Card card);

    // Информирование о перетасовке колоды
    void signalShuffled();

public slots:
    // Запрос карты для игрока
    void slotRequestCard();

private:
    // Заполнение колоды основными картами
    void setupBase();

    // Добавление EXPLODE карт
    void addExtraCards(int playersNumber);

private:
    std::deque<Card> _deck;
};

#endif // DECK_H
