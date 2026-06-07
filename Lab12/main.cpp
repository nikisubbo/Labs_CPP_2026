#include <iostream>
#include <limits> 
#include "Seq7.h"
#include "Seq12.h"
#include "Seq24.h"
#include "iter15.h"
int main() {
    int choice = 0;
    std::string menu_message = "Menu:\n1)Seq7\n2)Seq12\n3)Seq24\n4)Iter15\n5)Exit\nSelect the desired task number: ";
    while (true) {
        std::cout << menu_message;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nError. Please enter a number between 1 and 5.\n\n";
            continue;
        }

        if (choice < 1 || choice > 6) {
            std::cout << "\nError. Please enter a number between 1 and 5.\n\n";
            continue;
        }
        if (choice == 5) {
            break;
        }
        switch (choice) {
        case 1:
            seq7();
            break;
        case 2:
            seq12();
            break;
        case 3:
            seq24();
            break;
        case 4:
            iter15();
            break;
        }
        std::cout << "\n";
    }

    std::cout << "Shut down..." << std::endl;
    return 0;
}