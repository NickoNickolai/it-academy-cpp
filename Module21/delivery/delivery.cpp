#include "delivery.h"
#include <iostream>

Delivery::Delivery(float weight, float distance)
    : _weight(weight), _distance(distance), _context(std::make_unique<DeliveryContext>())
{}

void Delivery::process()
{
    _context->setStrategy(StrategyType::GROUND);
    printResult(_context->executeStrategy(_weight, _distance));
    _context->setStrategy(StrategyType::AIR);
    printResult(_context->executeStrategy(_weight, _distance));
    _context->setStrategy(StrategyType::EXPRESS);
    printResult(_context->executeStrategy(_weight, _distance));
}

void Delivery::printResult(double result) const
{
    std::cout << _context->strategyName() << " delivery cost: "<< result << std::endl;
}
