#include <iostream>
#include "sup.h"
#include "Graf1.h"
#include "Graf4.h"
#include "Graf8.h"
int main() {
    int choice = 0;
    std::string menu_message = "Menu:\n1)Graf1\n2)Graf4\n3)Graf8\n4)Exit\nSelect the desired task number: ";
    while (choice != 4) {
        std::cout << menu_message;
        choice = Input_Int();
        if (choice < 1 || choice > 4) {
            std::cout << "\nError. Please enter a number between 1 and 4.\n\n";
            continue;
        }
        switch (choice) {
        case 1:
            Graf1();
            break;
        case 2:
            Graf4();
            break;
        case 3:
            Graf8();
            break;
        }
        std::cout << "\n";
    }

    std::cout << "Shut down..." << std::endl;
    return 0;
}