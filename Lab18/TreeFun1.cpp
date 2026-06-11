#include <iostream>
#include "sup.h"
#include "BSTDlist.h"
#include "TreeFun1.h"
void TreeFun1() {
	std::cout << "!!! Task: TreeFun1 !!!" << std::endl;
	std::cout << "Convert a binary search tree into a doubly linked list without using additional memory\n\n" << std::endl;
	BinaryTree Tree;
	HowToFill(Tree);
	std::cout << "\n The original search tree:\n ";
	Tree.show();
	Node* List = Tree.convert_to_list();
	std::cout << "\nResulting doubly linked list: ";
	Tree.show_list(List);

	Node* current = List;
	while (current != nullptr) {
		Node* next = current->get_right(); 
		delete current;                   
		current = next;                    
	}
}