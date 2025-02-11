#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>

// Вспомогательная ф-ция вывода списка машин в консоль
template <typename T>
void displayCarsList(const std::string &hdr, const std::vector<std::shared_ptr<T>> &cars)
{
    std::cout << hdr << ": [";
    for(decltype(cars.size()) i = 0; i < cars.size(); ++i)
    {
        std::cout << "{" << i + 1 << ":\"" << cars[i]->name() << "\"}";
        if(i < cars.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

// Вспомогательная ф-ция вывода информации о машинах в консоль
template <typename T>
void displayCarsInfo(const std::string &hdr, const std::vector<std::shared_ptr<T>> &cars)
{
    std::cout << hdr << ":" << std::endl;
    for(decltype(cars.size()) i = 0; i < cars.size(); ++i)
    {
        std::cout << i + 1 << ": " << *cars[i] << std::endl;
    }
};

#endif // DISPLAY_H
