#ifndef ARRPROC_H
#define ARRPROC_H

#include <vector>
#include <mutex>
#include <thread>
#include <future>

class ArrProc
{
public:
    ArrProc();

    // Запуск выполнения операций в разных потоках
    void process();

    // Операции над массивом
#if defined(USE_PROMISE)
    void sum(std::promise<int> prm);
    void max(std::promise<int> prm);
    void min(std::promise<int> prm);
#elif defined(USE_ASYNC)
    int sum();
    int max();
    int min();
#else
    void sum();
    void max();
    void min();
#endif
    // Вывод в консоль целевого массива
    void printArray() const;

    // Вывод в консоль результатов операций над массивом
    void printResults() const;

private:
    std::vector<int> _arr;
#if !defined(USE_PROMISE) && !defined(USE_ASYNC)
    std::mutex _syncSum;
    std::mutex _syncMax;
    std::mutex _syncMin;
#endif
    int _sum;
    int _max;
    int _min;
};

#endif // ARRPROC_H
