#include "arrproc.h"
#include <iostream>
#include <ctime>

#define ARRAY_MIN 1
#define ARRAY_MAX 100
#define ARRAY_SIZE 100

ArrProc::ArrProc()
{
    std::srand(std::time(nullptr));
    _arr.resize(ARRAY_SIZE);
    for(auto &value : _arr)
    {
        value = rand() % (ARRAY_MAX - ARRAY_MIN + 1) + ARRAY_MIN;
    }
    _sum = 0;
    _max = ARRAY_MIN;
    _min = ARRAY_MAX;
}

void ArrProc::process()
{
#if defined(USE_PROMISE)
    std::promise<int> prmSum;
    std::promise<int> prmMax;
    std::promise<int> prmMin;
    std::future<int> futSum = prmSum.get_future();
    std::future<int> futMax = prmMax.get_future();
    std::future<int> futMin = prmMin.get_future();
    std::thread thrSum(&ArrProc::sum, this, std::move(prmSum));
    std::thread thrMax(&ArrProc::max, this, std::move(prmMax));
    std::thread thrMin(&ArrProc::min, this, std::move(prmMin));
    thrSum.join();
    thrMax.join();
    thrMin.join();
    _sum = futSum.get();
    _max = futMax.get();
    _min = futMin.get();
#elif defined(USE_ASYNC)
    std::future<int> futSum = std::async(std::launch::async, &ArrProc::sum, this);
    std::future<int> futMax = std::async(std::launch::async, &ArrProc::max, this);
    std::future<int> futMin = std::async(std::launch::async, &ArrProc::min, this);
    _sum = futSum.get();
    _max = futMax.get();
    _min = futMin.get();
#else
    std::thread thrSum(&ArrProc::sum, this);
    std::thread thrMax(&ArrProc::max, this);
    std::thread thrMin(&ArrProc::min, this);
    thrSum.join();
    thrMax.join();
    thrMin.join();
#endif
}

#if defined(USE_PROMISE)
void ArrProc::sum(std::promise<int> prm)
{
    int sumVal = 0;
    for(const auto &value : _arr)
    {
        sumVal += value;
    }
    prm.set_value(sumVal);
}

void ArrProc::max(std::promise<int> prm)
{
    int maxVal = ARRAY_MIN;
    for(const auto &value : _arr)
    {
        maxVal = std::max(maxVal, value);
    }
    prm.set_value(maxVal);
}

void ArrProc::min(std::promise<int> prm)
{
    int minVal = ARRAY_MAX;
    for(const auto &value : _arr)
    {
        minVal = std::min(minVal, value);
    }
    prm.set_value(minVal);
}
#elif defined(USE_ASYNC)
int ArrProc::sum()
{
    int sumVal = 0;
    for(const auto &value : _arr)
    {
        sumVal += value;
    }
    return sumVal;
}

int ArrProc::max()
{
    int maxVal = ARRAY_MIN;
    for(const auto &value : _arr)
    {
        maxVal = std::max(maxVal, value);
    }
    return maxVal;
}

int ArrProc::min()
{
    int minVal = ARRAY_MAX;
    for(const auto &value : _arr)
    {
        minVal = std::min(minVal, value);
    }
    return minVal;
}
#else
void ArrProc::sum()
{
    for(const auto &value : _arr)
    {
        _syncSum.lock();
        _sum += value;
        _syncSum.unlock();
    }
}

void ArrProc::max()
{
    for(const auto &value : _arr)
    {
        std::unique_lock<std::mutex> lock(_syncMax);
        _max = std::max(_max, value);
    }
}

void ArrProc::min()
{
    for(const auto &value : _arr)
    {
        std::lock_guard<std::mutex> guard(_syncMin);
        _min = std::min(_min, value);
    }
}
#endif
void ArrProc::printArray() const
{
    for(const auto &value : _arr)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

void ArrProc::printResults() const
{
    std::cout << "sum = " << _sum << ", max = " << _max
              << ", min = " << _min << std::endl;
}
