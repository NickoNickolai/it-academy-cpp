#include <iostream>
#include <memory>
#include "leafy.h"
#include "needles.h"
#include "pine.h"
#include "oak.h"
#include "birch.h"
#include "maple.h"

int main()
{
    std::cout << "-> Setup forests..." << std::endl;
    std::unique_ptr<Tree> tree1 = std::make_unique<Pine>();
    std::unique_ptr<Tree> tree2 = std::make_unique<Oak>("Very-old-oak");
    std::unique_ptr<Tree> tree3 = std::make_unique<Birch>(Tree::typeToName(TreeType::BIRCH));

    std::cout << "-> Total trees: " << Tree::totalTrees() << std::endl;

    std::unique_ptr<Needles> forest1 = std::make_unique<Needles>();
    forest1->addTree(tree1);
    forest1->addTree(tree2);
    forest1->growUp(TreeType::PINE);
    forest1->growUp(TreeType::MAPLE, 3);

    std::unique_ptr<Forest> forest2 = std::make_unique<Leafy>();
    if(tree2) { forest2->addTree(tree2); }
    forest2->addTree(tree3);
    forest2->growUp(TreeType::MAPLE, 2);
    forest2->growUp(TreeType::PINE);

    std::cout << "-> Total trees: " << Tree::totalTrees() << std::endl;

    std::cout << "-> Forest 1 trees [" << forest1->getTreesNumber() << "]: " << std::endl;
    forest1->wind();
    std::cout << "-> Forest 2 trees [" << forest2->getTreesNumber() << "]: " << std::endl;
    forest2->wind();

    std::cout << "-> Trees count by type:" << std::endl;
    std::cout << Tree::typeToName(TreeType::PINE)  << ":\t" << Pine::totalTrees()  << std::endl;
    std::cout << Tree::typeToName(TreeType::BIRCH) << ":\t" << Birch::totalTrees() << std::endl;
    std::cout << Tree::typeToName(TreeType::OAK)   << ":\t" << Oak::totalTrees()   << std::endl;
    std::cout << Tree::typeToName(TreeType::MAPLE) << ":\t" << Maple::totalTrees() << std::endl;

    return 0;
}
