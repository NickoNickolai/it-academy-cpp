#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <vector>
#include "player.h"
#include "deck.h"
#include "pool.h"
#include "card.h"

enum class Event
{
    UNKNOWN,
    REQ_PLAYER_CARD  = 1,
    REQ_NOPE_CARD    = 2,
    REQ_DECK_CARD    = 3,
    RECV_PLAYER_CARD = 4,
    RECV_NOPE_CARD   = 5,
    RECV_DECK_CARD   = 6
};

class Game : public QObject
{
    Q_OBJECT
public:
    Game();

    // Добавление игрока
    void addPlayer(PlayerType type, const std::string &name = "");

    // Инициализация новой игры
    void newGame();

signals:
    // Сигнал о необходимости удаления карты из кэша
    void signalPopFuture();

private:
    // Инициализация всех состояний для новой игры
    void init();

    // Обработка произошедшего события игры
    void processEvent(Event event);

    // Обработка карты от игрока при взрыве
    void processPlayerInExplodeState();

    // Обработка карты от игрока перед этапом отмены
    void processPlayerInSafeState();

    // Обработка карты от игрока после этапа отмены
    void processCard();

    // Обработка этапа отмены
    void processNopeCard();

    // Обработка карты от колоды
    void processDeckCard();

private:
    Deck _deck;
    Pool _pool;
    Card _plrCard;
    Card _dckCard;
    bool _nopeState;
    PlayerState _state;
};

#endif // GAME_H
