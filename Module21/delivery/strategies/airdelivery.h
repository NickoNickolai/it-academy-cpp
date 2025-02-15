#ifndef AIRDELIVERY_H
#define AIRDELIVERY_H

#include "ideliverystrategy.h"

class AirDelivery : public IDeliveryStrategy
{
public:
    AirDelivery(double weightRate, double distanceRate);

    // Расчёт стоимости доставки в зависимости от веса и расстояния
    double calculateCost(float weight, float distance) const override;

private:
    double _weightRate;
    double _distanceRate;
};

#endif // AIRDELIVERY_H
