#ifndef CALCULATION_H
#define CALCULATION_H

#include <functional>

class Calculation
{
public:
    static double calculate(double a, std::function<double(double)> op);
    static double calculate(double a, double b, std::function<double(double, double)> op);
};

#endif // CALCULATION_H
