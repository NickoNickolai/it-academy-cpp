#include "oak.h"
#include <iostream>

int Oak::_cnt = 0;

Oak::Oak()
    : Oak(typeToName(TreeType::OAK))
{}

Oak::Oak(const std::string &name)
    : Tree(TreeType::OAK, name)
{
    ++_cnt;
}

Oak::~Oak()
{
    --_cnt;
}

void Oak::wind() const
{
    std::cout << Tree::typeToName(getType()) << std::endl;
}
