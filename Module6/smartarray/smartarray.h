#ifndef STRINGPROCESSOR_H
#define STRINGPROCESSOR_H

#include <memory>

class SmartArray
{
public:
    SmartArray(int n = 10);

    // Заполнение массива значениями, введенными пользователем
    void fill();

    // Поиск минимума и максимума
    void find_min_max();

    // Вывод массива в консоль
    void print() const;

    // Получение минимума и максимума
    int min() const;
    int max() const;

private:
    std::unique_ptr<int[]> _uptr;
    int _n;
    int _min;
    int _max;
};

#endif // STRINGPROCESSOR_H
