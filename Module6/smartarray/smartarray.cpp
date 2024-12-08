#include "smartarray.h"
#include <iostream>
#include <climits>

SmartArray::SmartArray(int n)
    : _n(n), _min(INT_MAX), _max(INT_MIN)
{
    _uptr = std::make_unique<int[]>(_n);
}

void SmartArray::fill()
{
    std::cout << "Enter " << _n << " integers: ";
    for(int i = 0; i < _n; ++i)
    {
        std::cin >> _uptr[i];
    }
    find_min_max();
}

void SmartArray::find_min_max()
{
    for(int i = 0; i < _n; ++i)
    {
        _min = std::min(_min, _uptr[i]);
        _max = std::max(_max, _uptr[i]);
    }
}

void SmartArray::print() const
{
    for(int i = 0; i < _n; ++i)
    {
        std::cout << _uptr[i] << ' ';
    }
    std::cout << std::endl;
}

int SmartArray::min() const
{
    return _min;
}

int SmartArray::max() const
{
    return _max;
}
