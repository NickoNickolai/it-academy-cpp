#include "forest.h"
#include <vector>
#include <iostream>

Forest::Forest(ForestType type)
    : _type(type)
{}

void Forest::addTree(std::unique_ptr<Tree> &tree)
{
    if(tree)
    {
        _trees.insert({ tree->getId(), std::move(tree) });
    }
}

void Forest::addTree(std::unique_ptr<Tree> &&tree)
{
    addTree(tree);
}

void Forest::cutTree(int id)
{
    _trees.erase(id);
}

void Forest::cutTreeType(TreeType type)
{
    std::vector<int> ids;
    for(auto &[id, tree] : _trees)
    {
        if(tree->getType() == type) { ids.push_back(id); }
    }
    for(auto id : ids)
    {
        cutTree(id);
    }
}

void Forest::cutAll()
{
    _trees.clear();
}

void Forest::printTrees() const
{
    for(auto& [id, tree] : _trees)
    {
        std::cout << tree->getName() << "#" << id << " ";
    }
    std::cout << std::endl;
}

void Forest::wind() const
{
    for(auto& [id, tree] : _trees)
    {
        tree->wind();
    }
}
