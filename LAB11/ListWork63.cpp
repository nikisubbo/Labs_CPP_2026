#include <iostream>
#include <fstream>
#include <string>
#include "Dlist.h"
void ListWork63(DoublyList& list) {
    std::string filename = "ListWork63.txt";
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error. File is not open '" << filename << "'.\n";
        return;
    }
    if (list.is_empty()) {
        std::cout << "Empty list.\n";
        file.close();
        return;
    }
    std::cout << "Writing list to file " << filename << "'...\n";
    bool first = true;
    while (!list.is_empty()) {
        int value = list.remove_back();
        if (!first) {
            file << " ";
        }
        file << value;
        first = false;
    }
    file.close();
    std::cout << "List empty.\n";
    std::cout << "Result saved to " << filename << "'.\n";
}