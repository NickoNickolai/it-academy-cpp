#ifndef CALCULATION_H
#define CALCULATION_H

#include <functional>
#ifdef USE_OPS_ARRAY
#include "operations.h"
#endif

enum class OperationType
{
    UNKNOWN = -1,
    DIV,
    SQRT,
    LOG,
    SQR_CIRC,

    SIZE
};

class Calculation
{
public:
    static double calculate(double a, std::function<double(double)> op);
    static double calculate(double a, double b, std::function<double(double, double)> op);
    static double calculate(double a, OperationType opType);
    static double calculate(double a, double b, OperationType opType);
#ifdef USE_OPS_ARRAY
private:
    static inline void *_ops[static_cast<int>(OperationType::SIZE)] =
    {
        static_cast<void *>(&ops::div),
        static_cast<void *>(&ops::sqrt),
        static_cast<void *>(&ops::log),
        static_cast<void *>(&ops::sqrCirc)
    };
#endif
};

#endif // CALCULATION_H
