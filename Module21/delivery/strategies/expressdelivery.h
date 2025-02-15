#ifndef EXPRESSDELIVERY_H
#define EXPRESSDELIVERY_H

#include "ideliverystrategy.h"

class ExpressDelivery : public IDeliveryStrategy
{
public:
    ExpressDelivery(double weightRate, double distanceRate, double expressRate);

    // Расчёт стоимости доставки в зависимости от веса и расстояния
    double calculateCost(float weight, float distance) const override;

private:
    double _weightRate;
    double _distanceRate;
    double _expressRate;
};

#endif // EXPRESSDELIVERY_H
