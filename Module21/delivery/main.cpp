#include "delivery.h"

int main()
{
    float weight = 50;
    float distance = 100;
    Delivery delivery(weight, distance);
    delivery.process();

    return 0;
}
