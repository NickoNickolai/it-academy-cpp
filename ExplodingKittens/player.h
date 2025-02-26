#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <deque>
#include "card.h"

#define FUTURE_LIMIT 3

struct PlayerState
{
    bool exploded;
    bool attacked;
    bool negated;
    bool skipped;
    bool shuffled;
    bool futured;
    bool favored;

    PlayerState() { memset(this, 0, sizeof(*this)); }
};

enum class PlayerType
{
    UNKNOWN,
    ROBOT,
    HUMAN,
    REMOTE_PLAYER
};

class Player : public QObject
{
    Q_OBJECT
public:
    Player(PlayerType type, std::string name);
    virtual ~Player() = default;

    // Добавление карты в руку
    virtual void addCard(Card card);

    // Удаление карт у игрока
    void clearHand() { _hand.clear(); }

    // Вывод списка карт игрока
    void printHand() const;

    // Вывод списка подсмотренных карт
    void printFuture() const;

    // Получение типа игрока
    auto type() const { return _type; }

    // Получение имени игрока
    auto name() const { return _name; }

    // Получение признака активности игрока (в игре или нет)
    bool valid() const { return _valid; }

    // Установка признака активности игрока (в игре или нет)
    void setValid(bool valid) { _valid = valid; }

signals:
    // Выдача карты в игру
    void signalSendCard(Card card);

    // Выдача отмены карты в игру
    void signalSendNope(bool nope);

    // Передача карты другому игроку по требованию
    void signalSendFavor(Card card);

    // Сигнал на отправку пакета по сети
    void signalSendNetworkData(QByteArray data);

public slots:
    // При поступлении запроса карты
    virtual void reqCard(PlayerState state) = 0;

    // При поступлении запроса отмены
    virtual void reqNope(PlayerState state) = 0;

    // Выдача карты по требованию другого игрока
    virtual void reqFavor() = 0;

    // Добавление карты в кэш
    virtual void addFuture(const Card &card);

    // Удаление карты из кэша
    virtual void popFuture();

    // Сброс кэша
    virtual void resetFuture();

protected:
    bool _valid;
    PlayerType _type;
    std::string _name;
    std::deque<Card> _hand;
    std::deque<Card> _future;
};

#endif // PLAYER_H
