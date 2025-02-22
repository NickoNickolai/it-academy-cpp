#include "calculation.h"
#include <iostream>
#include "exceptions.h"

double Calculation::calculate(double a, ops::unary_t op)
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

double Calculation::calculate(double a, double b, ops::binary_t op)
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

double Calculation::calculate(double a, OperationType opType)
{
    try
    {
        switch(opType)
        {
#ifdef USE_OPS_ARRAY
        case OperationType::SQRT:
        case OperationType::LOG:
        case OperationType::SQR_CIRC:
        {
            auto index = static_cast<int>(opType);
            auto op = std::get<ops::unary_t>(_ops[index]);
            return op(a);
            break;
        }
#else
        case OperationType::SQRT:
            return ops::sqrt(a);
            break;
        case OperationType::LOG:
            return ops::log(a);
            break;
        case OperationType::SQR_CIRC:
            return ops::sqrCirc(a);
            break;
#endif
        default:
            throw exc::InvalidOperation("no known operations for 1 argument");
            break;
        }
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
    catch(const exc::InvalidOperation &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return NAN;
}

double Calculation::calculate(double a, double b, OperationType opType)
{
    try
    {
        switch(opType)
        {
#ifdef USE_OPS_ARRAY
        case OperationType::DIV:
        {
            auto index = static_cast<int>(opType);
            auto op = std::get<ops::binary_t>(_ops[index]);
            return op(a, b);
        }
#else
        case OperationType::DIV:
            return ops::div(a, b);
            break;
#endif
        default:
            throw exc::InvalidOperation("no known operations for 2 arguments");
            break;
        }
    }
    catch(const std::invalid_argument &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    catch(const exc::InvalidOperation &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return NAN;
}
