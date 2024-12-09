#include "uniquearray.h"
#include <iostream>

void UniqueArray::fill(std::unique_ptr<int[]> &arr, int n)
{
    std::cout << "Enter " << n << " integers: ";
    for(int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
}

void UniqueArray::print(std::unique_ptr<int[]> &arr, int n)
{
    for(int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}
