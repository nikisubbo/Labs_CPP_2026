#include <iostream>
#include <limits> 
#include "stack.h"
#include "queue.h"
#include "list.h"
int main() {
    int choice = 0;
    std::string menu_message = "Menu:\n1)Stack menu\n2)Queue menu\n3)List menu\n4)ListWork22\n5)ListWork60\n6)Exit\nSelect the desired task number: ";
    while (true) {
        std::cout << menu_message;
        if (!(std::cin >> choice)) {
            std::cin.clear();  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nError. Please enter a number between 1 and 6.\n\n";
            continue;  
        }

        if (choice < 1 || choice > 6) {
            std::cout << "\nError. Please enter a number between 1 and 6.\n\n";
            continue;
        }
        if (choice == 6) {
            break;
        }
        switch (choice) {
        case 1:
            stack_menu();
            break;
        case 2:
            queue_menu();
            break;
        case 3:
            list_menu();
            break;
        }
        std::cout << "\n"; 
    }

    std::cout << "Shut down..." << std::endl;
    return 0;
}