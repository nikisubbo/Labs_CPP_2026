#include <iostream>
#include <limits> 
#include "Dlist.h"
#include "DoubleClist.h"
#include "CircularList.h"
int main() {
    int choice = 0;
    std::string menu_message = "Menu:\n1)Circual list menu\n2)Double Circular list menu\n3)Double list menu\n4)ListWork22\n5)ListWork60\n6)Exit\nSelect the desired task number: ";
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
            clist_menu();
            break;
        case 2:
            Dclist_menu();
            break;
        case 3:
            Dlist_menu();
            break;
        }
        std::cout << "\n";
    }

    std::cout << "Shut down..." << std::endl;
    return 0;
}