#ifndef BIRCH_H
#define BIRCH_H

#include "tree.h"

class Birch : public Tree
{
public:
    // Получение текущего числа инстанцированных берёз
    static int totalTrees() { return _cnt; }

public:
    Birch();
    Birch(const std::string &name);
    ~Birch();

    // Вывод в консоль типа дерева
    void wind() const override;

private:
    static int _cnt;
};

#endif // BIRCH_H
