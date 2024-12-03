#include "matrix.h"
#include <iostream>
#include <iomanip>

static inline int field_width(int number)
{
    int fw = 0;
    while(number)
    {
        number /= 10;
        ++fw;
    }
    return ++fw;
}

template<typename T>
static inline T sqr(const T &a)
{
    return a * a;
}

Matrix::Matrix(int m)
    : Matrix(m, m)
{}

Matrix::Matrix(int m, int n)
    : _m(m), _n(n)
{
#ifdef USE_DIM2
    _mat = new int *[_m];
    for(int i = 0; i < _m; ++i)
    {
        _mat[i] = new int[_n];
    }
#else
    _mat = new int[_m * _n];
#endif
    _w = field_width(sqr(std::max(_m, _n)));
}

Matrix::~Matrix()
{
#ifdef USE_DIM2

    for(int i = 0; i < _m; ++i)
    {
        delete[] _mat[i];
    }
    delete[] _mat;
#else
    delete[] _mat;
#endif
}

void Matrix::fill()
{
    for(int i = 0; i < _m; ++i)
    {
        for(int j = 0; j < _n; ++j)
        {
#ifdef USE_DIM2
            _mat[i][j] = i * j;
#else
            _mat[i * _m + j] = i * j;
#endif
        }
    }
}

void Matrix::print()
{
    for(int i = 0; i < _m; ++i)
    {
        for(int j = 0; j < _n; ++j)
        {
#ifdef USE_DIM2
            std::cout << std::setw(_w) << _mat[i][j];
#else
            std::cout << std::setw(_w) << _mat[i * _m + j];
#endif
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
