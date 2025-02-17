#ifndef POOL_H
#define POOL_H

#include <QObject>
#include <vector>
#include "player.h"

class Pool : public QObject
{
    Q_OBJECT
public:
    Pool();

    // Добавление игрока
    void addPlayer(PlayerType type, const std::string &name);

    // Удаление всех игроков из пула
    void clear();

    // Переход хода к следующему/предыдущему игроку
    void switchToNextPlayer();
    void switchToPrevPlayer();

    // Инвалидация игрока
    void defeatPlayer();

    // Инициализация карт в руках
    void setupHands();

    // Вывод в консоль карт игроков
    void print() const;

    // Добавление карты игроку в руку
    void addCardToPlayer(int n, Card card);

    // Получение числа игроков
    auto size() const { return _players.size(); }

    // Получение текущего игрока
    Player *player() const { return _players[_currPlayerIndex]; }

    // Получение победителя при его наличии
    Player *winner();

public slots:
    // Действия при перетасовке колоды
    void slotShuffled();

    // Удаление карты из кэша
    void slotPopFuture();

signals:
    // Запрос карты из колоды
    void signalRequestCard(int n);

    // Выдача карты в игру
    void signalSendCard(Card card);

    // Выдача отмены карты в игру
    void signalSendNope(bool nope);

private:
    std::vector<Player *> _players;
    int _currPlayerIndex;
    Player *_winner;
};

#endif // POOL_H
