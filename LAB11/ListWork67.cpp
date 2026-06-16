#include <iostream>
#include <fstream>
#include "CircularList.h"
void CircularList::ListWork67(const std::string& filename) {
    if (!head) {
        std::cout << "Emty list\n";
        return;
    }
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error. File is not open" << filename << "'\n";
        return;
    }
    std::cout << "Writting to file...\n";
    CNode* current = head;
    CNode* prev = head;
    while (prev->next != head) {
        prev = prev->next;
    }
    while (current != nullptr) {
        file << current->data << " ";
        if (current == current->next) {
            delete current;
            this->head = nullptr;      
            current = nullptr;         
        }
        else {
            prev->next = current->next;
            CNode* toDelete = current;
            current = current->next; 
            delete toDelete;
            prev = current;
            current = current->next;
        }
    }
    file.close();
    std::cout << "Successfully. Check file " << filename << "\n";
    std::cout << "Empty list";
}