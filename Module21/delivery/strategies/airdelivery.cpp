#include "airdelivery.h"

#define AIR_FACTOR 1.5

AirDelivery::AirDelivery(double weightRate, double distanceRate)
    : _weightRate(weightRate), _distanceRate(distanceRate)
{}

double AirDelivery::calculateCost(float weight, float distance) const
{
    return AIR_FACTOR * _weightRate * weight + _distanceRate * distance;
}
