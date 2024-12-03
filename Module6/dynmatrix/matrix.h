#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public:
    Matrix(int m);
    Matrix(int m, int n);
    ~Matrix();

    // Заполнение матрицы значениями i * j
    void fill();

    // Вывод матрицы в консоль
    void print();

private:
    int _m = 3;
    int _n = 3;
    int _w = 0;
#ifdef USE_DIM2
    int **_mat = nullptr;
#else
    int *_mat = nullptr;
#endif
};

#endif // MATRIX_H
