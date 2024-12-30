#ifndef MAPLE_H
#define MAPLE_H

#include "tree.h"

class Maple : public Tree
{
public:
    // Получение текущего числа инстанцированных клёнов
    static int totalTrees() { return _cnt; }

public:
    Maple();
    Maple(const std::string &name);
    ~Maple();

    // Вывод в консоль типа дерева
    void wind() const override;

private:
    static int _cnt;
};

#endif // MAPLE_H
