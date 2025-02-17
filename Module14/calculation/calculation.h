#ifndef CALCULATION_H
#define CALCULATION_H

#ifdef USE_OPS_ARRAY
#include <variant>
#endif
#include "operations.h"

enum class OperationType
{
    UNKNOWN = -1,
    DIV,
    SQRT,
    LOG,
    SQR_CIRC
};

class Calculation
{
public:
    static double calculate(double a, ops::unary_t op);
    static double calculate(double a, double b, ops::binary_t op);
    static double calculate(double a, OperationType opType);
    static double calculate(double a, double b, OperationType opType);
#ifdef USE_OPS_ARRAY
private:
    static inline std::variant<ops::unary_t, ops::binary_t> _ops[] =
    {
        ops::div,
        ops::sqrt,
        ops::log,
        ops::sqrCirc
    };
#endif
};

#endif // CALCULATION_H
