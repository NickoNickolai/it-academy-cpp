#include "player.h"

#include <cstdlib>
#include <ctime>

Player::Player(const std::string &name)
    : _name(name)
{
    std::srand(std::time(nullptr));
}

void Player::set_name(const std::string &name)
{
    _name = name;
}

std::string Player::name() const
{
    return _name;
}

int Player::roll_number() const
{
    static int sign = -1;
    sign *= -1;
    return (rand() % 5 + 1) * sign;
}
