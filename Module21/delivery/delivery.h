#ifndef DELIVERY_H
#define DELIVERY_H

#include <memory>
#include "deliverycontext.h"

class Delivery
{
public:
    Delivery(float weight, float distance);

    // Выполнение расчётов по доставке
    void process();

private:
    void printResult(double result) const;

private:
    float _weight;
    float _distance;
    std::unique_ptr<DeliveryContext> _context;
};

#endif // DELIVERY_H
