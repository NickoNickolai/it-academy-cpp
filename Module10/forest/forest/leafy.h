#ifndef LEAFY_H
#define LEAFY_H

#include "forest.h"

class Leafy : public Forest
{
public:
    Leafy();

    // Выращивание деревьев заданного типа в лесу
    void growUp(TreeType type, int count = 1) override;

    // Добавление дерева в лес
    void addTree(std::unique_ptr<Tree> &tree) override;
};

#endif // LEAFY_H
