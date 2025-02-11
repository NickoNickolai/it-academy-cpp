#include "car.h"

Car::Car(const std::string &name)
    : Car(name, false)
{}

Car::Car(const std::string &name, bool isRepaired)
    : _name(name), _isRepaired(isRepaired)
{}

std::ostream &operator <<(std::ostream &out, const Car &car)
{
    return out << (car.isRepaired() ? "fixed" : "broken")
           << " \"" << car.name() << "\"";
}
