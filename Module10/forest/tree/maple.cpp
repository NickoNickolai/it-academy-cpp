#include "maple.h"
#include <iostream>

int Maple::_cnt = 0;

Maple::Maple()
    : Maple(typeToName(TreeType::MAPLE))
{}

Maple::Maple(const std::string &name)
    : Tree(TreeType::MAPLE, name)
{
    ++_cnt;
}

Maple::~Maple()
{
    --_cnt;
}

void Maple::wind() const
{
    std::cout << Tree::typeToName(getType()) << std::endl;
}
