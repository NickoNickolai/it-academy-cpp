#ifndef SHAREDARRAY_H
#define SHAREDARRAY_H

#include <memory>

class SharedArray
{
public:
    // Заполнение массива значениями, введенными пользователем
    static void fill(std::weak_ptr<int[]> arr, int n);

    // Вычисление суммы элементов массива
    static int sum(std::weak_ptr<int[]> arr, int n);

    // Поиск минимума и максимума
    static void min_max(std::weak_ptr<int[]> arr, int n, int &mn, int &mx);

    // Вывод массива в консоль
    static void print(std::weak_ptr<int[]> arr, int n);
};

#endif // SHAREDARRAY_H
