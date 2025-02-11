#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <chrono>

enum class OrderState
{
    UNKNOWN,
    NEW,
    PROCESSING,
    SHIPPED
};

class Order
{
public:
    Order(double total);
    Order(const Order &other);
    Order(Order &&other);
    Order &operator=(const Order &other);
    Order &operator=(Order &&other);

    // Получение состояния заказа в виде строки
    std::string stateName() const;

    // Сеттеры полей класса
    void setState(OrderState state) { _state = state; }

    // Геттеры для полей класса
    auto number() const { return _number; }
    auto total() const { return _total; }
    auto state() const { return _state; }
    auto time() const { return _time; }

private:
    static inline int _uid = 0;

private:
    int _number;
    double _total;
    OrderState _state;
    std::chrono::time_point<std::chrono::system_clock> _time;
};

#endif // ORDER_H
