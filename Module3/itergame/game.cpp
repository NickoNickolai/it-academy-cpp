#include <iostream>

#include "game.h"

Game::Game()
    : _rounds_limit(100),
      _max_score(50),
      _curr_score(0),
      _verbose(false)
{}

Game &Game::instance()
{
    static Game instance;
    return instance;
}

void Game::add_player(const Player &player)
{
    _players.push_back(player);
}

void Game::clear_players()
{
    _players.clear();
}

void Game::set_rounds_limit(int rounds_limit)
{
    _rounds_limit = rounds_limit;
}

void Game::set_max_score(int max_score)
{
    _max_score = max_score;
}

void Game::play()
{
    _curr_score = 0;

    for(int i = 0; i < _rounds_limit; ++i)
    {
        for(const auto &player : _players)
        {
            int number = player.roll_number();
            _curr_score += number;

            if(_verbose)
            {
                std::cout << player.name() << " rolls " << number
                          << ", total score = " << _curr_score << std::endl;
            }

            if(_curr_score > _max_score)
            {
                std::cout << player.name() << " won!" << std::endl;
                return;
            }
        }
    }

    std::cout << "Draw" << std::endl;
}
