#include "randvector.h"

int main()
{
    RandVector vec;
    vec.fill();
    vec.print();
    vec.process();
    vec.print();

    return 0;
}
