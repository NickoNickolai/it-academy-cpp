#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
public:
    Player(const std::string &name);

    // Задать имя игрока
    void set_name(const std::string &name);

    // Получить имя игрока
    std::string name() const;

    // Выдать число в диапазоне [-5..-1] либо [1..5]
    int roll_number() const;

private:
    std::string _name;
};

#endif // PLAYER_H
