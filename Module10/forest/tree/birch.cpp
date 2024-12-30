#include "birch.h"
#include <iostream>

int Birch::_cnt = 0;

Birch::Birch()
    : Birch(typeToName(TreeType::BIRCH))
{}

Birch::Birch(const std::string &name)
    : Tree(TreeType::BIRCH, name)
{
    ++_cnt;
}

Birch::~Birch()
{
    --_cnt;
}

void Birch::wind() const
{
    std::cout << Tree::typeToName(getType()) << std::endl;
}
