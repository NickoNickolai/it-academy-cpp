#include "expressdelivery.h"

ExpressDelivery::ExpressDelivery(double weightRate, double distanceRate, double expressRate)
    : _weightRate(weightRate), _distanceRate(distanceRate), _expressRate(expressRate)
{}

double ExpressDelivery::calculateCost(float weight, float distance) const
{
    return (_weightRate * weight + _distanceRate * distance) * _expressRate;
}
