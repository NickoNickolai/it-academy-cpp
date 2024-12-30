#include "forest.h"
#include <vector>
#include <iostream>

void Forest::growUp(TreeType type, int count)
{
    for(int i = 0; i < count; ++i)
    {
        auto tree = std::make_unique<Tree>(type);
        addTree(std::move(tree));
    }
}

void Forest::addTree(std::unique_ptr<Tree> tree)
{
    if(tree)
    {
        _trees.insert({ tree->getId(), std::move(tree) });
    }
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

Forest operator+(Forest &a, Forest &b)
{
    Forest forest;
    for(auto &[id, tree] : a._trees) { forest.addTree(std::move(tree)); }
    for(auto &[id, tree] : b._trees) { forest.addTree(std::move(tree)); }
    a.cutAll();
    b.cutAll();
    return forest;
}
