#include <iostream>
#include "numshifter.h"

int main()
{
    std::cout << "Enter a number: ";
    int n;
    std::cin >> n;

    NumShifter shifter(n);
    shifter.print_result();

    return 0;
}
