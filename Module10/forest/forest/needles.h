#ifndef NEEDLES_H
#define NEEDLES_H

#include "forest.h"

class Needles : public Forest
{
public:
    Needles();

    // Выращивание деревьев заданного типа в лесу
    void growUp(TreeType type, int count = 1) override;

    // Добавление дерева в лес
    void addTree(std::unique_ptr<Tree> &tree) override;
};

#endif // NEEDLES_H
