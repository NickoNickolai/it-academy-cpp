#ifndef OPERATIONS_H
#define OPERATIONS_H

#if _MSC_VER
#define _USE_MATH_DEFINES
#endif
#include <cmath>
#include <functional>
#include <stdexcept>
#include "exceptions.h"

namespace ops
{
// Операция деления
std::function<double(double, double)> div = [](double a, double b)
{
    if(b == 0)
    {
        throw std::invalid_argument("division by zero");
    }
    return a / b;
};

// Операция извлечения квадратного корня
std::function<double(double)> sqrt = [](double a)
{
    if(a < 0)
    {
        throw std::domain_error("argument is negative");
    }
    return std::sqrt(a);
};

// Операция вычисления логарифма
std::function<double(double)> log = [](double a)
{
    if(a < 0)
    {
        throw exc::InvalidLogArgument("argument is negative");
    }
    return std::log(a);
};

// Операция вычисления площади круга
std::function<double(double)> sqrCirc = [](double r)
{
    if(r < 0)
    {
        throw exc::InvalidRadusArgument("argument is negative");
    }
    return M_PI * r * r;
};
}

#endif // OPERATIONS_H
