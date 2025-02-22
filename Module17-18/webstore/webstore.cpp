#include "webstore.h"
#include <iostream>
#include <algorithm>

WebStore::WebStore()
{
    _ordersCommon.reserve(RESERVE_SIZE);
    _ordersProcessing.reserve(RESERVE_SIZE);
}

void WebStore::makeOrder(double total)
{
    _ordersCommon.push_back(Order(total));
}

void WebStore::updateOrders()
{
    std::transform(_ordersCommon.begin(), _ordersCommon.end(), _ordersCommon.begin(), [](auto &order)
    {
        auto currTime = std::chrono::system_clock::now();
        auto ordrTime = order.time();
        if(currTime - ordrTime > std::chrono::seconds(DELAY_SIZE))
        {
            order.setState(OrderState::PROCESSING);
        }
        return std::move(order);
    });
}

void WebStore::sendToProcessing()
{
    std::cout << "---> Send orders to processing..." << std::endl;
    auto pos = std::partition(_ordersCommon.begin(), _ordersCommon.end(), [](auto &order)
    {
        return order.state() == OrderState::PROCESSING;
    });
    std::move(_ordersCommon.begin(), pos, std::back_inserter(_ordersProcessing));

    printCommonOrders();

    _ordersCommon.erase(_ordersCommon.begin(), pos);
    std::cout << "<--- Sending to processing done!" << std::endl;
}

void WebStore::printHugeOrder(double threshold) const
{
    auto it = std::find_if(_ordersCommon.begin(), _ordersCommon.end(), [threshold](auto &order)
    {
        return order.total() > threshold;
    });
    if(it != _ordersCommon.end())
    {
        std::cout << "Found huge order #" << it->number() << ": " << it->total() << std::endl;
    }
    else
    {
        std::cout << "No huge orders found" << std::endl;
    }
}

void WebStore::printCommonOrders() const
{
    std::cout << "Common orders:" << std::endl;
    for(const auto &order : _ordersCommon)
    {
        std::cout << "#" << order.number() << ": " << order.total()
                  << " (" << order.stateName() << ")" << std::endl;
    }
}

void WebStore::printProcessingOrders() const
{
    std::cout << "Processing orders:" << std::endl;
    for(const auto &order : _ordersProcessing)
    {
        std::cout << "#" << order.number() << ": " << order.total()
                  << " (" << order.stateName() << ")" << std::endl;
    }
}
