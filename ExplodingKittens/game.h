#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QEventLoop>
#include <vector>
#include <queue>
#include "player.h"
#include "deck.h"
#include "pool.h"
#include "card.h"

enum class Event
{
    UNKNOWN,
    REQUEST_PLAY_CARD,
    RECEIVE_PLAY_CARD,
    REQUSET_NOPE_CARD,
    RECEIVE_NOPE_CARD,
    REQUEST_DECK_CARD,
    RECEIVE_DECK_CARD,
    REQUEST_FAVOR_CARD,
    RECEIVE_FAVOR_CARD
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

    // Старт игры
    void start();

signals:
    // Сигнал о необходимости удаления карты из кэша
    void signalPopFuture();

    // Сигнал отправки игрового сообщения игроку-клиенту
    void signalGameMessage(std::string message);

private:
    // Инициализация всех состояний для новой игры
    void init();

    // Добавление игрового события в очередь событий
    void addEvent(Event event);

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
    Card _favCard;
    bool _nopeState;
    PlayerState _state;
    std::queue<Event> _events;
    QEventLoop _loop;
    bool _isRunning;
};

#endif // GAME_H
