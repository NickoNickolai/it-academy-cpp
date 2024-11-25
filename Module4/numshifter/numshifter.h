#ifndef NUMSHIFTER_H
#define NUMSHIFTER_H

class NumShifter
{
public:
    NumShifter(int n, int shift = 2);

    // Вывод результата побитового сдвига
    void print_result() const;

private:
    // Проверка на чётность и знак
    bool is_positive_even() const;

private:
    int _n;
    int _shift;
};

#endif // NUMSHIFTER_H
