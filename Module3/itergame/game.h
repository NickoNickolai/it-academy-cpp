#ifndef GAME_H
#define GAME_H

#include <vector>
#include "player.h"

class Game
{
public:
    // Получение объекта игры
    static Game &instance();

    // Добавить игрока в игру
    void add_player(const Player &player);

    // Удалить всех игроков из игры
    void clear_players();

    // Установить ограничение числа раундов
    void set_rounds_limit(int rounds_limit = 100);

    // Установить макс счёт игры
    void set_max_score(int max_score = 50);

    // Запуск игры
    void play();

private:
    Game();
    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;

private:
    std::vector<Player> _players;
    int _rounds_limit;
    int _max_score;
    int _curr_score;
    bool _verbose;
};

#endif // GAME_H
