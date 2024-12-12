#include "sharedarray.h"
#include <iostream>
#include <climits>

void SharedArray::fill(std::weak_ptr<int[]> arr, int n)
{
    if(auto ptr = arr.lock())
    {
        std::cout << "Enter " << n << " integers: ";
        for(int i = 0; i < n; ++i)
        {
            std::cin >> ptr[i];
        }
    }
    else
    {
        std::cout << "Invalid array storage" << std::endl;
    }
}

int SharedArray::sum(std::weak_ptr<int[]> arr, int n)
{
    int total = 0;
    if(auto ptr = arr.lock())
    {
        for(int i = 0; i < n; ++i)
        {
            total += ptr[i];
        }
    }
    return total;
}

void SharedArray::min_max(std::weak_ptr<int[]> arr, int n, int &mn, int &mx)
{
    if(auto ptr = arr.lock())
    {
        mn = INT_MAX;
        mx = INT_MIN;
        for(int i = 0; i < n; ++i)
        {
            mn = std::min(mn, ptr[i]);
            mx = std::max(mx, ptr[i]);
        }
    }
}

void SharedArray::print(std::weak_ptr<int[]> arr, int n)
{
    if(auto ptr = arr.lock())
    {
        for(int i = 0; i < n; ++i)
        {
            std::cout << ptr[i] << ' ';
        }
        std::cout << std::endl;
    }
}
