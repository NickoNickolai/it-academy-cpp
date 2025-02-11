#include <iostream>
#include <thread>
#include "webstore.h"

void makeDelay(int seconds = DELAY_SIZE + 1)
{
    std::cout << "Udpate orders in ";
    while(seconds > 0)
    {
        std::cout << seconds << " ";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        --seconds;
    }
    std::cout << std::endl;
}

int main()
{
    WebStore store;

    store.makeOrder(5000);
    store.makeOrder(6000);
    store.printCommonOrders();
    store.printHugeOrder();

    makeDelay();

    store.makeOrder(50);
    store.makeOrder(60);
    store.updateOrders();
    store.printCommonOrders();

    store.sendToProcessing();
    store.printCommonOrders();
    store.printProcessingOrders();
    store.printHugeOrder();

    return 0;
}
