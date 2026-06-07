#include <iostream>
#include "Dlist.h"

void ListWork46(DoublyList& list) {
    if (list.is_empty()) {
        std::cout << "Empty list.\n";
    }
    else {
        std::cout << "Original list: ";
        list.print();
        std::cout << "\n";
    }
    DNode* P1 = list.get_head();
    DNode* P2 = list.get_tail();
    DNode* barrier = create_barrier_and_link(P1, P2);
    list.disconnect();
    std::cout << "Barrier element address: " << barrier << "\n";
    std::cout << "Barrier value: " << barrier->data << "\n";
    std::cout << "Barrier->next: " << barrier->next << "\n";
    std::cout << "Barrier->prev: " << barrier->prev << "\n";
    std::cout << "Cyclic list: ";
    DNode* current = barrier;
    bool first = true;
    do {
        if (!first) std::cout << " <-> ";
        std::cout << current->data;
        current = current->next;
        first = false;
    } while (current != barrier);
    std::cout << " <-> \n";
    current = barrier->next; 
    while (current != barrier) {
        DNode* to_delete = current;
        current = current->next;
        delete to_delete;
    }
    delete barrier; 
    std::cout << "All valus deleted.\n";
}