#ifndef SERVICESTATION_H
#define SERVICESTATION_H

#include <vector>
#include <memory>
#include <iostream>
#include "garage.h"
#include "display.h"

class PassengerCar;
class CargoCar;

template <typename T>
class ServiceStation
{
public:
    ServiceStation(int limit = 5);

    // Добавление машины в СТО
    void addCar(std::weak_ptr<T> car);

    // Ремонт всех машин в СТО и перемещение их в гараж
    void repairAll();

    // Вывод списка машин СТО в консоль
    void displayStation() const;

    // Вывод списка машин гаража в консоль
    void displayGarage() const;

private:
    Garage<T> _garage;
    std::vector<std::shared_ptr<T>> _cars;
    decltype(_cars.size()) _limit;
};

template <typename T>
ServiceStation<T>::ServiceStation(int limit)
    : _limit(limit)
{}

template <typename T>
void ServiceStation<T>::addCar(std::weak_ptr<T> car)
{
    if(auto pcar = car.lock())
    {
        if(_cars.size() < _limit)
        {
            _cars.push_back(pcar);
        }
        else
        {
            std::cout << "Limit is excedeed: unable to add \""
                      << pcar->name() << "\"" << std::endl;
        }
    }
}

template <typename T>
void ServiceStation<T>::repairAll()
{
    for(auto car : _cars)
    {
        car->repair();
        _garage.addToGarage(car);
    }
    _cars.clear();
}

template <>
void ServiceStation<PassengerCar>::displayStation() const
{
    displayCarsList("Psngrs queue", _cars);
}

template <>
void ServiceStation<CargoCar>::displayStation() const
{
    displayCarsList("Cargos queue", _cars);
}

template <typename T>
void ServiceStation<T>::displayStation() const
{
    displayCarsList("Unvrsl queue", _cars);
}

template <typename T>
void ServiceStation<T>::displayGarage() const
{
    _garage.displayAll();
}

#endif // SERVICESTATION_H
