#include "randvector.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>

RandVector::RandVector(int n)
{
    _vec.resize(n);
    std::srand( std::time( nullptr ) );
}

void RandVector::fill()
{
    for(auto &el : _vec)
    {
        el = rand() % 100 + 1;
    }
}

void RandVector::process()
{
    std::sort(_vec.begin(), _vec.end());
}

void RandVector::print() const
{
    for(auto &el : _vec)
    {
        std::cout << std::setw(4) << el;
    }
    std::cout << std::endl;
}
