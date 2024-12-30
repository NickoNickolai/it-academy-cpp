#include <iostream>
#include <memory>
#include "forest.h"

int main()
{
    std::cout << "-> Setup forests..." << std::endl;
    auto tree1 = std::make_unique<Tree>(TreeType::PINE);
    auto tree2 = std::make_unique<Tree>(TreeType::OAK, "Very-old-oak");
    auto tree3 = std::make_unique<Tree>(TreeType::BIRCH, Tree::typeToName(TreeType::BIRCH));

    Forest forest1;
    forest1.addTree(std::move(tree1));
    forest1.addTree(std::move(tree2));
    forest1.growUp(TreeType::MAPLE, 3);

    Forest forest2;
    forest2.addTree(std::move(tree3));
    forest2.growUp(TreeType::MAPLE, 2);

    Forest forest3;

    auto printForests = [ & ]()
    {
        std::cout << "Forest 1[" << forest1.getTreesNumber() << "]: "; forest1.printTrees();
        std::cout << "Forest 2[" << forest2.getTreesNumber() << "]: "; forest2.printTrees();
        std::cout << "Forest 3[" << forest3.getTreesNumber() << "]: "; forest3.printTrees();
        std::cout << "Trees  : " << Tree::totalTrees() << std::endl;
    };
    printForests();

    std::cout << "-> Cut all maples in forest 1..." << std::endl;
    forest1.cutTreeType(TreeType::MAPLE);
    printForests();

    std::cout << "-> Merge forest 1 with forest 2 into forest 3..." << std::endl;
    forest3 = forest1 + forest2;
    printForests();

    std::cout << "-> Grow some trees in forest 1..." << std::endl;
    forest1.growUp(TreeType::MAPLE);
    forest1.growUp(TreeType::BIRCH);
    printForests();

    std::cout << "-> Cut all trees in forest 3..." << std::endl;
    forest3.cutAll();
    printForests();

    return 0;
}
