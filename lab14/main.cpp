#include <iostream>
#include <limits> 
#include "Assoc2.h"
#include "Assoc17.h"
#include "Assoc21.h"
int main() {
    int choice = 0;
    std::string menu_message = "Menu:\n1)Assoc2\n2)Assoc17\n3)Assoc21\n4)Exit\nSelect the desired task number: ";
    while (true) {
        std::cout << menu_message;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nError. Please enter a number between 1 and 4.\n\n";
            continue;
        }

        if (choice < 1 || choice > 4) {
            std::cout << "\nError. Please enter a number between 1 and 4.\n\n";
            continue;
        }
        if (choice == 4) {
            break;
        }
        switch (choice) {
        case 1:
            Assoc2();
            break;
        case 2:
            Assoc17();
            break;
        case 3:
            Assoc21();
            break;
        }
        std::cout << "\n";
    }

    std::cout << "Shut down..." << std::endl;
    return 0;
}