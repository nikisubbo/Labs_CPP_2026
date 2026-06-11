#include <iostream>
#include "sup.h"
#include "BSiterator.h"
void TreeFun3() {
	std::cout << "!!! Task: TreeFun1 !!!" << std::endl;
	std::cout << "Implement an iterator interface for a binary tree that will return" <<
		"the values of the elements in the tree nodes in the order left-root-right.";
	BTree Tree;
	HowToFill(Tree);
	std::cout << "\n The original search tree:\n ";
	Tree.print();
	std::cout << "Iterator traversal: ";
	TreeIterator it = Tree.get_iter();
	while (it.has_next()) {
		std::cout << it.next() << " ";
	}
}