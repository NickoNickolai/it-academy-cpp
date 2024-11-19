#include <iostream>
#include "factorial.h"

int main()
{
    Factorial f;
    int n = 5;
    std::cout << n << "! = " << f.factorial( n ) << std::endl;

    return 0;
}
