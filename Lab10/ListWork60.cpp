#include <iostream>
#include "list.h"
#include "input.h"
#include <iostream>
#include "list.h"
#include "input.h"
void ListWork60(LinkedList &l) {
    int m;
    std::cout << "Enter M: ";
    m = Input_Int();
    std::cout << std::endl;
    LinkedList new_l(l);
    new_l.insert_sorted(m);
    ListNode* p = new_l.get_head();
    std::cout << "Address of the first element: " << p << std::endl;
    std::cout << "Resulting sorted list: ";
    new_l.print();
    std::cout << std::endl;
}