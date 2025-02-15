#ifndef GROUNDDELIVERY_H
#define GROUNDDELIVERY_H

#include "ideliverystrategy.h"

class GroundDelivery : public IDeliveryStrategy
{
public:
    GroundDelivery(double distanceRate);

    // Расчёт стоимости доставки в зависимости от веса и расстояния
    double calculateCost(float weight, float distance) const override;

private:
    double _distanceRate;
};

#endif // GROUNDDELIVERY_H
