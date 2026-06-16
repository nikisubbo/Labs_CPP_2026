#include "Dynamic4.h"
#include "stack.h"
#include "input.h"
#include <iostream>
void Dynamic4(Stack &s) {
    std::cout << "Start Dynamic 4 task\n";
    s.print();
    Node* ad = s.get_top();
    //std::cout << ad;
    //std::cout <<"\n" <<  ad->data;
    std::cout << "Top: " << ad;
    std::cout << "\nEnd Dynamic 4 task" << std::endl;
}