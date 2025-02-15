#include "deliverycontext.h"
#include "grounddelivery.h"
#include "airdelivery.h"
#include "expressdelivery.h"

DeliveryContext::DeliveryContext(double rateWeight, double rateDistance, double rateExpress)
    : _rateWeight(rateWeight), _rateDistance(rateDistance), _rateExpress(rateExpress)
{
    addStrategy(StrategyType::GROUND);
    addStrategy(StrategyType::AIR);
    addStrategy(StrategyType::EXPRESS);
}

void DeliveryContext::addStrategy(StrategyType strategy)
{
    switch(strategy)
    {
    case StrategyType::GROUND:
        _strategies[strategy] = std::make_unique<GroundDelivery>(_rateWeight);
        break;
    case StrategyType::AIR:
        _strategies[strategy] = std::make_unique<AirDelivery>(_rateWeight, _rateDistance);
        break;
    case StrategyType::EXPRESS:
        _strategies[strategy] = std::make_unique<ExpressDelivery>(_rateWeight, _rateDistance, _rateExpress);
        break;
    default:
        break;
    }
}

void DeliveryContext::setStrategy(StrategyType strategy)
{
    _strategy = strategy;
}

double DeliveryContext::executeStrategy(float weight, float distance) const
{
    switch(_strategy)
    {
    case StrategyType::GROUND:
    case StrategyType::AIR:
    case StrategyType::EXPRESS:
        return _strategies.at(_strategy)->calculateCost(weight, distance);
    default:
        break;
    }
    return -1;
}

std::string DeliveryContext::strategyName() const
{
    switch(_strategy)
    {
    case StrategyType::GROUND:
        return "Ground";
    case StrategyType::AIR:
        return "Air";
    case StrategyType::EXPRESS:
        return "Express";
    default:
        return "Unknown";
    }
}
