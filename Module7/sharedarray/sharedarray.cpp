#include "sharedarray.h"
#include <iostream>
#include <climits>

void SharedArray::fill(std::weak_ptr<int[]> arr, int n)
{
    std::cout << "Enter " << n << " integers: ";
    auto ptr = arr.lock();
    for(int i = 0; i < n; ++i)
    {
        std::cin >> ptr[i];
    }
}

int SharedArray::sum(std::weak_ptr<int[]> arr, int n)
{
    int total = 0;
    auto ptr = arr.lock();
    for(int i = 0; i < n; ++i)
    {
        total += ptr[i];
    }
    return total;
}

void SharedArray::min_max(std::weak_ptr<int[]> arr, int n, int &mn, int &mx)
{
    mn = INT_MAX;
    mx = INT_MIN;
    auto ptr = arr.lock();
    for(int i = 0; i < n; ++i)
    {
        mn = std::min(mn, ptr[i]);
        mx = std::max(mx, ptr[i]);
    }
}

void SharedArray::print(std::weak_ptr<int[]> arr, int n)
{
    auto ptr = arr.lock();
    for(int i = 0; i < n; ++i)
    {
        std::cout << ptr[i] << ' ';
    }
    std::cout << std::endl;
}
