#ifndef FOREST_H
#define FOREST_H

#include <unordered_map>
#include <memory>
#include "tree.h"

class Forest
{
public:
    // Выращивание деревьев заданного типа в лесу
    void growUp(TreeType type, int count = 1);

    // Добавление дерева в лес
    void addTree(std::unique_ptr<Tree> tree);

    // Вырубка дерева
    void cutTree(int id);

    // Вырубка деревьев заданного типа
    void cutTreeType(TreeType type);

    // Вырубка всех деревьев
    void cutAll();

    // Вывод в консоль списка деревьев в лесу
    void printTrees() const;

    // Получение числа деревьев в лесу
    auto getTreesNumber() const { return _trees.size(); }

public:
    // Объединение 2 лесов в 1
    friend Forest operator+(Forest &a, Forest &b);

private:
    std::unordered_map<int, std::unique_ptr<Tree>> _trees;
};

#endif // FOREST_H
