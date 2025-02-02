#if _MSC_VER
#define _USE_MATH_DEFINES
#endif
#include <iostream>
#include <functional>
#include "operations.h"
#include "calculation.h"

int main()
{
    std::cout << "--> Valid operations:" << std::endl;
    {
        double a = 2, b = 7;
        double result = Calculation::calculate(a, b, ops::div);
        std::cout << a << "/" << b << " = " << result << std::endl;
    }
    {
        double a = 16;
        double result = Calculation::calculate(a, ops::sqrt);
        std::cout << "sqrt(" << a << ") = " << result << std::endl;
    }
    {
        double a = 2.7;
        double result = Calculation::calculate(a, ops::log);
        std::cout << "log(" << a << ") = " << result << std::endl;
    }
    {
        double r = 1;
        double result = Calculation::calculate(r, ops::sqrCirc);
        std::cout << "sqrCirc(" << r << ") = " << result << std::endl;
    }

    std::cout << "--> Operations with exceptions:" << std::endl;
    {
        double a = 2, b = 0;
        double result = Calculation::calculate(a, b, ops::div);
        std::cout << a << "/" << b << " = " << result << std::endl;
    }
    {
        double a = -16;
        double result = Calculation::calculate(a, ops::sqrt);
        std::cout << "sqrt(" << a << ") = " << result << std::endl;
    }
    {
        double a = -2.7;
        double result = Calculation::calculate(a, ops::log);
        std::cout << "log(" << a << ") = " << result << std::endl;
    }
    {
        double r = -1;
        double result = Calculation::calculate(r, ops::sqrCirc);
        std::cout << "sqrCirc(" << r << ") = " << result << std::endl;
    }

    return 0;
}
