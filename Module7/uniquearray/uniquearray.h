#ifndef UNIQUEARRAY_H
#define UNIQUEARRAY_H

#include <memory>

class UniqueArray
{
public:
    // Заполнение массива значениями, введенными пользователем
    static void fill(std::unique_ptr<int[]> &arr, int n);

    // Вывод массива в консоль
    static void print(std::unique_ptr<int[]> &arr, int n);
};

#endif // UNIQUEARRAY_H
