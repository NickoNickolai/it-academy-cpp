#include <iostream>
#include "game.h"

int main()
{
    auto &game = Game::instance();

#ifdef USE_SCENARIO

    // Классическая игра

    game.add_player(Player("Player 1"));
    game.add_player(Player("Player 2"));

    game.play();

    // Игры с множеством игроков

    game.add_player(Player("Player 3"));
    game.add_player(Player("Player 4"));
    game.add_player(Player("Player 5"));

    for(int i = 0; i < 10; ++i)
    {
        game.play();
    }

    // Повышение частоты победных исходов

    game.set_max_score(20);

    for(int i = 0; i < 10; ++i)
    {
        game.play();
    }

#else
    std::string name;
    std::cout << "Enter Player 1 name: ";
    std::getline(std::cin, name);
    game.add_player(Player(name));

    std::cout << "Enter Player 2 name: ";
    std::getline(std::cin, name);
    game.add_player(Player(name));

    do
    {
        game.play();

        std::cout << "New game? [y,n]: ";
        char ch;
        std::cin >> ch;

        if(ch == 'n' || ch == 'N')
        {
            break;
        }
    }
    while(true);

#endif

    return 0;
}
