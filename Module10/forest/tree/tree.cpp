#include "tree.h"
#include <iostream>

int Tree::_cnt = 0;
int Tree::_uid = 0;

Tree::Tree(TreeType type, const std::string &name)
    : _id(++_uid), _type(type), _name(name)
{
    ++_cnt;
}

Tree::Tree(TreeType type)
    : Tree(type, typeToName(type))
{}

Tree::Tree(const Tree &other)
    : Tree(other.getType())
{}

Tree::~Tree()
{
    --_cnt;
}

void Tree::wind() const
{
    std::cout << "Tree #" << getId() << ": " << getName() << std::endl;
}

std::string Tree::typeToName(TreeType type)
{
    switch(type)
    {
    case TreeType::PINE:  return "pine";
    case TreeType::BIRCH: return "birch";
    case TreeType::OAK:   return "oak";
    case TreeType::MAPLE: return "maple";
    default:              return "unknown";
    }
}
