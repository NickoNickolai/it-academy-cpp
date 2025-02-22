#include "grounddelivery.h"

GroundDelivery::GroundDelivery(double distanceRate)
    : _distanceRate(distanceRate)
{}

double GroundDelivery::calculateCost(float, float distance) const
{
    return _distanceRate * distance;
}
