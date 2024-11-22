#include "tablemult.h"

#include <iostream>
#include <iomanip>

int field_width(int number)
{
    int fw = 0;

    while(number)
    {
        number /= 10;
        ++fw;
    }

    return ++fw;
}

TableMult::TableMult(int m)
    : TableMult(m, m)
{}

TableMult::TableMult(int m, int n)
    : _m(m), _n(n)
{
    int number = std::max(_m, _n) * std::max(_m, _n);
    _w = field_width(number);
}

void TableMult::print_via_for()
{
    std::string h = "FOR loop";
    int hw = ((_n + 1) * _w + h.size()) / 2;
    std::cout << std::setw(hw) << h << std::endl;

    std::cout << std::setw(_w) << '|';

    for(int i = 1; i <= _n; ++i)
    {
        std::cout << std::setw(_w) << i;
    }

    std::cout << '\n';

    for(int i = 0; i < (_n + 1) * _w; ++i)
    {
        std::cout << '-';
    }

    std::cout << '\n';

    for(int i = 1; i <= _m; ++i)
    {
        std::cout << std::setw(_w) << std::to_string(i) + '|';

        for(int j = 1; j <= _n; ++j)
        {
            std::cout << std::setw(_w) << i *j;
        }

        std::cout << '\n';
    }

    std::cout << '\n';
}

void TableMult::print_via_while()
{
    std::string h = "WHILE loop";
    int hw = ((_n + 1) * _w + h.size()) / 2;
    std::cout << std::setw(hw) << h << std::endl;

    std::cout << std::setw(_w) << '|';

    int i = 1;

    while(i <= _n)
    {
        std::cout << std::setw(_w) << i++;
    }

    std::cout << '\n';

    i = 0;

    while(i < (_n + 1) * _w)
    {
        std::cout << '-';
        ++i;
    }

    std::cout << '\n';

    i = 1;

    while(i <= _m)
    {
        std::cout << std::setw(_w) << std::to_string(i) + '|';

        int j = 1;

        while(j <= _n)
        {
            std::cout << std::setw(_w) << i *j;
            ++j;
        }

        std::cout << '\n';

        ++i;
    }

    std::cout << '\n';
}

void TableMult::print_via_dowhile()
{
    std::string h = "DO-WHILE loop";
    int hw = ((_n + 1) * _w + h.size()) / 2;
    std::cout << std::setw(hw) << h << std::endl;

    std::cout << std::setw(_w) << '|';

    int i = 1;

    do
    {
        std::cout << std::setw(_w) << i++;
    }
    while(i <= _n);

    std::cout << '\n';

    i = 0;

    do
    {
        std::cout << '-';
        ++i;
    }
    while(i < (_n + 1) * _w);

    std::cout << '\n';

    i = 1;

    do
    {
        std::cout << std::setw(_w) << std::to_string(i) + '|';

        int j = 1;

        do
        {
            std::cout << std::setw(_w) << i *j;
            ++j;
        }
        while(j <= _n);

        std::cout << '\n';

        ++i;
    }
    while(i <= _m);

    std::cout << '\n';
}
