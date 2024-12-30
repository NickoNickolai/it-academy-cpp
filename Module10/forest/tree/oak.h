#ifndef OAK_H
#define OAK_H

#include "tree.h"

class Oak : public Tree
{
public:
    // Получение текущего числа инстанцированных дубов
    static int totalTrees() { return _cnt; }

public:
    Oak();
    Oak(const std::string &name);
    ~Oak();

    // Вывод в консоль типа дерева
    void wind() const override;

private:
    static int _cnt;
};

#endif // OAK_H
