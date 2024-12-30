#ifndef FOREST_H
#define FOREST_H

#include <unordered_map>
#include <memory>
#include "tree.h"

enum class ForestType
{
    UNKNOWN,
    LEAFY,
    NEEDLES
};

class Forest
{
public:
    Forest(ForestType type);
    virtual ~Forest() = default;

    // Выращивание деревьев заданного типа в лесу
    virtual void growUp(TreeType type, int count = 1) = 0;

    // Добавление дерева в лес (перемещение при вставке в контейнер)
    virtual void addTree(std::unique_ptr<Tree> &tree);

    // Вырубка дерева
    void cutTree(int id);

    // Вырубка деревьев заданного типа
    void cutTreeType(TreeType type);

    // Вырубка всех деревьев
    void cutAll();

    // Вывод в консоль списка деревьев в лесу
    void printTrees() const;

    // Вывод в консоль информации о каждом дереве
    void wind() const;

    // Получение типа леса
    auto getType() { return _type; }

    // Получение числа деревьев в лесу
    auto getTreesNumber() const { return _trees.size(); }

protected:
    // Добавление дерева в лес (перемещение при передаче в ф-цию)
    void addTree(std::unique_ptr<Tree> &&tree);

private:
    ForestType _type;
    std::unordered_map<int, std::unique_ptr<Tree>> _trees;
};

#endif // FOREST_H
