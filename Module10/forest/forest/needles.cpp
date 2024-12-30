#include "needles.h"
#include <iostream>
#include "pine.h"

Needles::Needles()
    : Forest(ForestType::NEEDLES)
{}

void Needles::growUp(TreeType type, int count)
{
    switch(type)
    {
    case TreeType::PINE:
        for(int i = 0; i < count; ++i)
        {
            auto tree = std::make_unique<Pine>();
            Forest::addTree(std::move(tree));
        }
        break;
    default:
        std::cout << "Error: growing " << Tree::typeToName(type)
                  << " trees in needles forest is prohibited" << std::endl;
    }
}

void Needles::addTree(std::unique_ptr<Tree> &tree)
{
    switch(tree->getType())
    {
    case TreeType::PINE:
        Forest::addTree(tree);
        break;
    default:
        std::cout << "Error: unable to add " << Tree::typeToName(tree->getType())
                  << " tree to needles forest" << std::endl;
    }
}
