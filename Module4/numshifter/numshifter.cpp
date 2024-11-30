#include "numshifter.h"
#include <iostream>

NumShifter::NumShifter(int n, int shift)
    : _n(n), _shift(shift)
{}

void NumShifter::print_result() const
{
    std::cout << "Shifted number: "
              << (is_positive_even() ? _n << _shift: _n >> _shift)
              << std::endl;
}

bool NumShifter::is_positive_even() const
{
    return !(_n & 1) && _n > 0;
}
