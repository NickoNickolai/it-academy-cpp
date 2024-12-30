#ifndef PINE_H
#define PINE_H

#include "tree.h"

class Pine : public Tree
{
public:
    // Получение текущего числа инстанцированных сосен
    static int totalTrees() { return _cnt; }

public:
    Pine();
    Pine(const std::string &name);
    ~Pine();

    // Вывод в консоль типа дерева
    void wind() const override;

private:
    static int _cnt;
};

#endif // PINE_H
