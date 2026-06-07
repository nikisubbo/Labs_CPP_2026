#include <iostream>
#include "DoubleClist.h"
void ListWork42(CircularDoublyList& l){
    Node* original_head = l.get_head();
    Node* original_tail = l.get_tail();
    if (original_head) {
        std::cout << "\nAddress of the first element: " << original_head << " value " << original_head ->data;
        std::cout << "\nAddress of the last element: " << original_tail << " value: " << original_tail->data << " ";
    }
    else {
        std::cout << "\nEmpty list.";
        return;
    }
    Node* new_tail = l.listwork42();
    std::cout << "\nAfter deleting ";
    if (l.is_empty()) {
        std::cout << "\nEmpty list";
    }
    else {
        l.print();
    }
    if (new_tail) {
        std::cout << "\nAddress of the last element after deleting: " << new_tail <<" value: " << new_tail->data << " ";
    }
    else {
        std::cout << "\nEmpyt list.";
    }
}