#include "leafy.h"
#include <iostream>
#include "birch.h"
#include "oak.h"
#include "maple.h"

Leafy::Leafy()
    : Forest(ForestType::LEAFY)
{}

void Leafy::growUp(TreeType type, int count)
{
    switch(type)
    {
    case TreeType::BIRCH:
        for(int i = 0; i < count; ++i)
        {
            auto tree = std::make_unique<Birch>();
            Forest::addTree(std::move(tree));
        }
        break;
    case TreeType::OAK:
        for(int i = 0; i < count; ++i)
        {
            auto tree = std::make_unique<Oak>();
            Forest::addTree(std::move(tree));
        }
        break;
    case TreeType::MAPLE:
        for(int i = 0; i < count; ++i)
        {
            auto tree = std::make_unique<Maple>();
            Forest::addTree(std::move(tree));
        }
        break;
    default:
        std::cout << "Error: growing " << Tree::typeToName(type)
                  << " trees in leafy forest is prohibited" << std::endl;
    }
}

void Leafy::addTree(std::unique_ptr<Tree> &tree)
{
    switch(tree->getType())
    {
    case TreeType::BIRCH:
    case TreeType::OAK:
    case TreeType::MAPLE:
        Forest::addTree(tree);
        break;
    default:
        std::cout << "Error: unable to add " << Tree::typeToName(tree->getType())
                  << " tree to leafy forest" << std::endl;
    }
}
