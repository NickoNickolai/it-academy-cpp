#ifndef GARAGE_H
#define GARAGE_H

#include <vector>
#include <memory>
#include "display.h"

template <typename T>
class Garage
{
public:
    // Добавление машины в гараж
    void addToGarage(std::weak_ptr<T> car);

    // Вывод информации о машинах в гараже в консоль
    void displayAll() const;

private:
    std::vector<std::shared_ptr<T>> _cars;
};

template <typename T>
void Garage<T>::addToGarage(std::weak_ptr<T> car)
{
    if(auto pcar = car.lock())
    {
        _cars.push_back(pcar);
    }
}

template <typename T>
void Garage<T>::displayAll() const
{
    displayCarsList("Garage queue", _cars);
}

#endif // GARAGE_H
