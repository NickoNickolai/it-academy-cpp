#include "calculation.h"
#include <iostream>
#include <cmath>
#include "exceptions.h"

double Calculation::calculate(double a, std::function<double(double)> op)
{
    try
    {
        return op(a);
    }
    catch(const std::domain_error &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    catch(const exc::InvalidLogArgument &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    catch(const exc::InvalidRadusArgument &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return NAN;
}

double Calculation::calculate(double a, double b, std::function<double(double, double)> op)
{
    try
    {
        return op(a, b);
    }
    catch(const std::invalid_argument &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return NAN;
}
