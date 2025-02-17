#include <QCoreApplication>
#include <memory>
#include <iostream>
#include "game.h"

// Ввод имени игрока
std::string inputGamerName();

// Ввод количества ботов в игре
size_t inputBotsCount();

// Создание игры
void createGame(const std::string &name, int bots);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto name = inputGamerName();
    auto bots = inputBotsCount();
    createGame(name, bots);

    return a.exec();
}

std::string inputGamerName()
{
    std::cout << "Enter your nickname: ";
    std::string name;
    std::cin >> name;
    return name;
}

size_t inputBotsCount()
{
    size_t bots = INT_MAX;
    std::string buf = std::to_string(bots);
    do
    {
        try
        {
            bots = std::stoul(buf);
        }
        catch(const std::invalid_argument &e)
        {
            std::cout << "Exception: invalid input" << std::endl;
        }
        if(bots > 0 && bots < 6)
        {
            break;
        }
        std::cout << "Enter number of bots: ";
    }
    while(std::cin >> buf);
    return bots;
}

void createGame(const std::string &name, int bots)
{
    auto game = std::make_unique<Game>();
    char ch = 0;
    do
    {
        if(std::tolower(ch) == 'y')
        {
            game->addPlayer(PlayerType::HUMAN, name);
            for(int i = 0; i < bots; ++i)
            {
                game->addPlayer(PlayerType::ROBOT);
            }
            game->newGame();
        }
        else if(std::tolower(ch) == 'n')
        {
            std::cout << "Bye" << std::endl;
            exit(0);
        }
        std::cout << "Play a new game? [y, n]: ";
    }
    while(std::cin >> ch);
}
