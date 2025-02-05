#ifndef OPERATIONS_H
#define OPERATIONS_H

#ifdef _MSC_VER
#define _USE_MATH_DEFINES
#include <math.h>
#else
#include <cmath>
#endif
#include <functional>
#include <stdexcept>
#include "exceptions.h"

namespace ops
{
using unary_t = std::function<double(double)>;
using binary_t = std::function<double(double, double)>;

// Операция деления
inline binary_t div = [](double a, double b)
{
    if(b == 0)
    {
        throw std::invalid_argument("division by zero");
    }
    return a / b;
};

// Операция извлечения квадратного корня
inline unary_t sqrt = [](double a)
{
    if(a < 0)
    {
        throw std::domain_error("argument is negative");
    }
    return std::sqrt(a);
};

// Операция вычисления логарифма
inline unary_t log = [](double a)
{
    if(a < 0)
    {
        throw exc::InvalidLogArgument("argument is negative");
    }
    return std::log(a);
};

// Операция вычисления площади круга
inline unary_t sqrCirc = [](double r)
{
    if(r < 0)
    {
        throw exc::InvalidRadusArgument("argument is negative");
    }
    return M_PI * r * r;
};
}

#endif // OPERATIONS_H
