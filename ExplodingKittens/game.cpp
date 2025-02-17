#include "game.h"
#include <iostream>
#include "logger.h"

Game::Game()
{
    // Ход колоды картой
    connect(&_deck, &Deck::signalSendCard, this, [this](Card card)
    {
        _dckCard = card;
        processEvent(Event::RECV_DECK_CARD);
    });

    // Колода перетасована - обнулить кэши игроков
    connect(&_deck, &Deck::signalShuffled, &_pool, &Pool::slotShuffled);

    // Взята карта из колоды - удалить верхнюю карту из кэшей игроков
    connect(this, &Game::signalPopFuture, &_pool, &Pool::slotPopFuture);

    // Добавление карты из колоды игроку в руку
    connect(&_pool, &Pool::signalRequestCard, this, [this](int n)
    {
        _pool.addCardToPlayer(n, _deck.takeCard());
    });

    // Ход игрока картой
    connect(&_pool, &Pool::signalSendCard, this, [this](Card card)
    {
        _plrCard = card;
        processEvent(Event::RECV_PLAYER_CARD);
    });

    // Ход игрока отменой
    connect(&_pool, &Pool::signalSendNope, this, [this](bool nope)
    {
        _nopeState = nope;
        processEvent(Event::RECV_NOPE_CARD);
    });
}

void Game::init()
{
    _deck.initBase();
    _pool.setupHands();
    _deck.initExtra(_pool.size());
    _plrCard = Card();
    _dckCard = Card();
    _nopeState = false;
    _state = PlayerState();
}

void Game::addPlayer(PlayerType type, const std::string &name)
{
    _pool.addPlayer(type, name);
}

void Game::newGame()
{
    init();
    processEvent(Event::REQ_PLAYER_CARD);
}

void Game::processEvent(Event event)
{
    if(auto winner = _pool.winner())
    {
        Logger::str(winner->name() + " won! Game over");
        _pool.clear();
        _state = PlayerState();
        return;
    }
    switch(event)
    {
    case Event::REQ_PLAYER_CARD:
    {
#ifdef USE_DEBUG
        _pool.print();
        _deck.print();
#endif
        _pool.player()->reqCard(_state);
        break;
    }
    case Event::RECV_PLAYER_CARD:
    {
        Logger::msg(_pool.player()->name(), _plrCard.name());
        if(_state.exploded)
        {
            _state.exploded = false;
            processPlayerInExplodeState();
        }
        else
        {
            processPlayerInSafeState();
        }
        break;
    }
    case Event::REQ_NOPE_CARD:
    {
        _pool.player()->reqNope(_state);
        break;
    }
    case Event::RECV_NOPE_CARD:
    {
        processNopeCard();
        break;
    }
    case Event::REQ_DECK_CARD:
    {
        _deck.slotRequestCard();
        break;
    }
    case Event::RECV_DECK_CARD:
    {
        emit signalPopFuture();
        processDeckCard();
        break;
    }
    default:
        break;
    }
}

void Game::processPlayerInExplodeState()
{
    if(_plrCard.type() == CardType::DEFUSE)
    {
        _deck.addCard(Card(CardType::EXPLODE));
        _deck.shuffle();
        if(!_state.attacked)
        {
            _pool.switchToNextPlayer();
        }
        processEvent(Event::REQ_PLAYER_CARD);
    }
    else
    {
        _state.attacked = false;
        _pool.defeatPlayer();
        Logger::str(_pool.player()->name() + " defeated...");
        _pool.switchToNextPlayer();
        processEvent(Event::REQ_PLAYER_CARD);
    }
}

void Game::processPlayerInSafeState()
{
    if(_plrCard.type() == CardType::ATTACK)
    {
        _state.attacked = true;
        _pool.switchToNextPlayer();
        processEvent(Event::REQ_NOPE_CARD);
    }
    else if(_plrCard.type() == CardType::SKIP)
    {
        _state.skipped = true;
        _pool.switchToNextPlayer();
        processEvent(Event::REQ_NOPE_CARD);
    }
    else if(_plrCard.type() == CardType::SHUFFLE)
    {
        _state.shuffled = true;
        _pool.switchToNextPlayer();
        processEvent(Event::REQ_NOPE_CARD);
    }
    else if(_plrCard.type() == CardType::FUTURE)
    {
        _state.futured = true;
        _pool.switchToNextPlayer();
        processEvent(Event::REQ_NOPE_CARD);
    }
    else if(_plrCard.type() == CardType::FAVOR)
    {
        _state.favored = true;
        _pool.switchToNextPlayer();
        processEvent(Event::REQ_NOPE_CARD);
    }
    else // PASS, CAT
    {
        processEvent(Event::REQ_DECK_CARD);
    }
}

void Game::processCard()
{
    // Действие карты SKIP
    if(_state.skipped)
    {
        _state.skipped = false;
        if(_state.attacked) // 1-й ход ATTACK засчитан
        {
            _state.attacked = false;
            _pool.switchToPrevPlayer();
        }
        processEvent(Event::REQ_PLAYER_CARD);
    }
    // Действие карты ATTACK
    if(_state.attacked)
    {
        processEvent(Event::REQ_DECK_CARD);
    }
    // Действие карты SHUFFLE
    if(_state.shuffled)
    {
        _state.shuffled = false;
        _pool.switchToPrevPlayer();
        _deck.shuffle();
        processEvent(Event::REQ_DECK_CARD);
    }
    // Действие карты FUTURE
    if(_state.futured)
    {
        _state.futured = false;
        _pool.switchToPrevPlayer();
        for(decltype(_deck.size()) i = 0; i < FUTURE_LIMIT && _deck.size() > i; ++i)
        {
            _pool.player()->addFuture(_deck[i]);
        }
#ifdef USE_DEBUG
        _pool.player()->printFuture();
#endif
        processEvent(Event::REQ_PLAYER_CARD);
    }
    // Действие карты FAVOR
    if(_state.favored)
    {
        _state.favored = false;
        auto currPlayer = _pool.player();
        auto card = currPlayer->favorCard();
        _pool.switchToPrevPlayer();
        auto prevPlayer = _pool.player();
        if(card.type() != CardType::PASS)
        {
            if(prevPlayer->type() == PlayerType::HUMAN)
            {
                Logger::msg(currPlayer->name() + " -> " + prevPlayer->name(), card.name());
            }
            prevPlayer->addCard(card);
        }
        else
        {
            Logger::msg(currPlayer->name(), "no card to take away...");
        }
        processEvent(Event::REQ_DECK_CARD);
    }
}

void Game::processNopeCard()
{
    if(_nopeState)
    {
        Logger::msg(_pool.player()->name(), "nope");
        _state.skipped = false;     // Карта SKIP отменена
        _state.attacked = false;    // Карта ATTACK отменена
        _state.shuffled = false;    // Карта SHUFFLE отменена
        _state.futured = false;     // Карта FUTURE отменена
        _state.favored = false;     // Карта FAVOR отменена
        _pool.switchToPrevPlayer();
        processEvent(Event::REQ_PLAYER_CARD);
    }
    else
    {
#ifdef USE_DEBUG
        Logger::msg(_pool.player()->name(), "allow " + _plrCard.name());
#endif
        processCard();
    }
}

void Game::processDeckCard()
{
    if(_dckCard.type() == CardType::EXPLODE)
    {
        _state.exploded = true;
        Logger::msg("Deck", _dckCard.name() + " -> " + _pool.player()->name());
    }
    else
    {
        _pool.player()->addCard(_dckCard);
        if(_pool.player()->type() == PlayerType::HUMAN)
        {
            Logger::msg("Deck", _dckCard.name() + " -> " + _pool.player()->name());
            _pool.player()->printHand();
            _pool.player()->printFuture();
        }
        else
        {
#ifdef USE_DEBUG
            Logger::msg("Deck", _dckCard.name() + " -> " + _pool.player()->name());
#endif
        }
        if(_state.attacked)
        {
            _state.attacked = false;
        }
        else
        {
            _pool.switchToNextPlayer();
        }
    }
    processEvent(Event::REQ_PLAYER_CARD);
}
