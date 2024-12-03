#include <iostream>
#include "smartarray.h"

int main()
{
    SmartArray a(10);
    a.fill();
    a.print();
    std::cout << "min = " << a.min() << ", max = " << a.max() << std::endl;

    return 0;
}
