#include "order.h"
#include <iostream>

Order::Order(double total)
    : _number(++_uid),
      _total(total),
      _state(OrderState::NEW),
      _time(std::chrono::system_clock::now())
{}

Order::Order(const Order &other)
{
    std::cout << "Order #" << other._number << " copied" << std::endl;
    _number = other._number;
    _total = other._total;
    _state = other._state;
    _time = other._time;
}

Order::Order(Order &&other)
{
    std::cout << "Order #" << other._number << " moved" << std::endl;
    _number = other._number;
    _total = other._total;
    _state = other._state;
    _time = other._time;
    other._number = 0;
    other._total = 0;
    other._state = OrderState::UNKNOWN;
    other._time = std::chrono::time_point<std::chrono::system_clock>();
}

Order &Order::operator=(const Order &other)
{
    std::cout << "Order #" << other._number << " copied by assignment" << std::endl;
    _number = other._number;
    _total = other._total;
    _state = other._state;
    _time = other._time;
    return *this;
}

Order &Order::operator=(Order &&other)
{
    std::cout << "Order #" << other._number << " moved by assignment" << std::endl;
    _number = other._number;
    _total = other._total;
    _state = other._state;
    _time = other._time;
    other._number = 0;
    other._total = 0;
    other._state = OrderState::UNKNOWN;
    other._time = std::chrono::time_point<std::chrono::system_clock>();
    return *this;
}

std::string Order::stateName() const
{
    switch(_state)
    {
    case OrderState::NEW:
        return "new";
    case OrderState::PROCESSING:
        return "processing";
    case OrderState::SHIPPED:
        return "shipped";
    default:
        return "unknown";
    }
}
