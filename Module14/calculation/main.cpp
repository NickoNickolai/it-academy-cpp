#include <iostream>
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
        double result = Calculation::calculate(a, OperationType::LOG);
        std::cout << "log(" << a << ") = " << result << std::endl;
    }
    {
        double r = 1;
        double result = Calculation::calculate(r, OperationType::SQR_CIRC);
        std::cout << "sqrCirc(" << r << ") = " << result << std::endl;
    }

    std::cout << "--> Operations with exceptions:" << std::endl;
    {
        double a = 2, b = 0;
        double result = Calculation::calculate(a, b, OperationType::DIV);
        std::cout << a << "/" << b << " = " << result << std::endl;
    }
    {
        double a = -16;
        double result = Calculation::calculate(a, OperationType::SQRT);
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
    {
        double a = 2, b = 7;
        Calculation::calculate(a, OperationType::DIV);
        Calculation::calculate(a, b, OperationType::SQRT);
    }

    return 0;
}
