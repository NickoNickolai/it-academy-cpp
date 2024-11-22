#ifndef TABLEMULT_H
#define TABLEMULT_H

class TableMult
{
public:
    TableMult(int m);
    TableMult(int m, int n);

    void print_via_for();
    void print_via_while();
    void print_via_dowhile();

private:
    int _m = 10;
    int _n = 10;
    int _w = 0;
};

#endif // TABLEMULT_H
