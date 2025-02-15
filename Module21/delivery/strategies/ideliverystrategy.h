#ifndef IDELIVERYSTRATEGY_H
#define IDELIVERYSTRATEGY_H

class IDeliveryStrategy
{
public:
    // Расчёт стоимости доставки в зависимости от веса и расстояния
    virtual double calculateCost(float weight, float distance) const = 0;
};

#endif // IDELIVERYSTRATEGY_H
