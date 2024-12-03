#ifndef RANDVECTOR_H
#define RANDVECTOR_H

#include <vector>

class RandVector
{
public:
    RandVector(int n = 10);

    // Заполнение вектора случайными числами
    void fill();

    // Обработка вектора
    void process();

    // Вывод вектора в консоль
    void print() const;

private:
    std::vector<int> _vec;
};

#endif // RANDVECTOR_H
