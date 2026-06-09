#include <iostream>
#include "sup.h"
#include "BTree.h"
void TreeFun13() {
    std::cout << "!!! Task: TreeFun13 !!!" << std::endl;
    std::cout << "Find and remove all duplicate subtrees, starting with the largest ones\n\n" << std::endl;
    ByTree Tree;
    HowToFill(Tree);
    std::cout << "\n The original tree:\n";
    Tree.print();
    Tree.remove_duplicate_subtrees();
    std::cout << "\n Tree after removing duplicate subtrees:\n";
    Tree.print();
}