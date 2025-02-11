#ifndef WEBSTORE_H
#define WEBSTORE_H

#include <vector>
#include "order.h"

#define HUGE_ORDER_THRESHOLD 5000
#define RESERVE_SIZE 100
#define DELAY_SIZE 5

class WebStore
{
public:
    WebStore();

    // Оформление заказа
    void makeOrder(double total);

    // Обновление состояния заказов из общего списка
    void updateOrders();

    // Перемещение заказов из общего списка в список процессинга
    void sendToProcessing();

    // Вывод в консоль заказа на большую сумму (больше порога)
    void printHugeOrder(double threshold = HUGE_ORDER_THRESHOLD) const;

    // Вывод в консоль заказов из общего списка
    void printCommonOrders() const;

    // Вывод в консоль заказов из списка обработки
    void printProcessingOrders() const;

public:
    std::vector<Order> _ordersCommon;
    std::vector<Order> _ordersProcessing;
};

#endif // WEBSTORE_H
