#include "printer.h"
#include <iostream>

void Printer::print(int value)
{
    std::cout << "int: " << value << std::endl;
}

void Printer::print(float value)
{
    std::cout << "float: " << value << std::endl;
}

void Printer::print(const std::string &value)
{
    std::cout << "string: " << value << std::endl;
}

void Printer::print(char *value, int n)
{
    if(!value)
    {
        return;
    }
    std::cout << "char[" << n << "]: ";
    for(int i = 0; i < n; ++i)
    {
        std::cout << +value[i] << ' ';
    }
    std::cout << std::endl;
}

void Printer::print(int *value, int n)
{
    if(!value)
    {
        return;
    }
    std::cout << "int[" << n << "]: ";
    for(int i = 0; i < n; ++i)
    {
        std::cout << value[i] << ' ';
    }
    std::cout << std::endl;
}

void Printer::print(const std::vector<int> &value)
{
    std::cout << "vector: ";
    for(auto &el : value)
    {
        std::cout << el << ' ';
    }
    std::cout << std::endl;
}

void Printer::print(std::shared_ptr<int> value)
{
    if(!value)
    {
        return;
    }
    std::cout << "shared_ptr<int>: " << *value << std::endl;
}

void Printer::print(std::unique_ptr<double> &value)
{
    if(!value)
    {
        return;
    }
    std::cout << "unique_ptr<double>: " << *value << std::endl;
}
