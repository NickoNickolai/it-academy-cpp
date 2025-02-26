#include <QCoreApplication>
#include <memory>
#include <iostream>
#include "game.h"
#include "remotegame.h"
#include "tcpserver.h"
#include "settings.h"

#define INI_FILE_NAME "config.ini"

// Ввод имени игрока
std::string inputGamerName();

// Ввод количества ботов в игре
size_t inputBotsCount();

// Ввод возможности сетевой игры
bool inputRemoteFlag(const std::string &msg);

// Создание игры
void createGame(const std::string &name, int bots);
void createRemoteGame();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Settings::load(INI_FILE_NAME);

    if(inputRemoteFlag("Are you client for remote game?"))
    {
        createRemoteGame();
    }
    else
    {
        auto name = inputGamerName();
        auto bots = inputBotsCount();
        createGame(name, bots);
    }

    std::cout << "That's all...";
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
        std::cout << "Enter number of bots [1-5]: ";
    }
    while(std::cin >> buf);
    return bots;
}

bool inputRemoteFlag(const std::string &msg)
{
    bool flag = false;
    char ch = 0;
    do
    {
        if(std::tolower(ch) == 'y')
        {
            flag = true;
            break;
        }
        else if(std::tolower(ch) == 'n')
        {
            break;
        }
        std::cout << msg << " [y, n]: ";
    }
    while(std::cin >> ch);
    return flag;
}

void createGame(const std::string &name, int bots)
{
    auto game = std::make_unique<Game>();
    char ch = 0;
    do
    {
        if(std::tolower(ch) == 'y')
        {
            if(!Settings::test())
            {
                game->addPlayer(PlayerType::HUMAN, name);
                if(inputRemoteFlag("Add remote player?"))
                {
                    game->addPlayer(PlayerType::REMOTE_PLAYER);
                }
            }
            for(int i = 0; i < bots; ++i)
            {
                game->addPlayer(PlayerType::ROBOT);
            }
            game->newGame();
            game->start();
            exit(0);
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

void createRemoteGame()
{
    auto name = inputGamerName();
    auto game = std::make_unique<RemoteGame>(name);
    game->newGame();
}
