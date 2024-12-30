#include "pine.h"
#include <iostream>

int Pine::_cnt = 0;

Pine::Pine()
    : Pine(typeToName(TreeType::PINE))
{}

Pine::Pine(const std::string &name)
    : Tree(TreeType::PINE, name)
{
    ++_cnt;
}

Pine::~Pine()
{
    --_cnt;
}

void Pine::wind() const
{
    std::cout << Tree::typeToName(getType()) << std::endl;
}
