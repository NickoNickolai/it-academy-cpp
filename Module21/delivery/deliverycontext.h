#ifndef DELIVERYCONTEXT_H
#define DELIVERYCONTEXT_H

#include <unordered_map>
#include <string>
#include <memory>
#include "ideliverystrategy.h"

#define RATE_WEIGHT 5
#define RATE_DISTANCE 10
#define RATE_EXPRESS 2.5

enum class StrategyType
{
    UNKNOWN = -1,
    GROUND,
    AIR,
    EXPRESS
};

class DeliveryContext
{
public:
    DeliveryContext(double rateWeight = RATE_WEIGHT,
                    double rateDistance = RATE_DISTANCE,
                    double rateExpress = RATE_EXPRESS);

    // Установка текущей стратегии
    void setStrategy(StrategyType strategy);

    // Выполнение расчётов по текущей стратегии
    double executeStrategy(float weight, float distance) const;

    // Получение названия текущей стратегии
    std::string strategyName() const;

private:
    void addStrategy(StrategyType strategy);

private:
    std::unordered_map<StrategyType, std::unique_ptr<IDeliveryStrategy>> _strategies;
    StrategyType _strategy;
    double _rateWeight;
    double _rateDistance;
    double _rateExpress;
};

#endif // DELIVERYCONTEXT_H
