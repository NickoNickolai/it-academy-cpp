#ifndef TREE_H
#define TREE_H

#include <string>

enum class TreeType
{
    UNKNOWN,
    PINE,
    BIRCH,
    OAK,
    MAPLE
};

class Tree
{
public:
    // Получение текущего числа инстанцированных объектов деревьев
    static int totalTrees() { return _cnt; }

    // Получение имени дерева по его типу
    static std::string typeToName(TreeType type);

public:
    Tree(TreeType type, const std::string &name);
    Tree(TreeType type);
    Tree(const Tree &other);
    virtual ~Tree();

    // Вывод в консоль информации о дереве
    virtual void wind() const = 0;

    // Геттеры доступа к полям класса
    auto getId() const { return _id; }
    auto getName() const { return _name; }
    auto getType() const { return _type; }

private:
    static int _cnt;
    static int _uid;

private:
    int _id;
    TreeType _type;
    std::string _name;
};

#endif // TREE_H
