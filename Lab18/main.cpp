#include <iostream>
#include "sup.h"
#include "TreeFun1.h"
#include "TreeFun3.h"
#include "TreeFun13.h"
int main() {
    int choice = 0;
    std::string menu_message = "Menu:\n1)TreeFun1\n2)TreeFun3\n3)TreeFun13\n4)Exit\nSelect the desired task number: ";
    while (choice != 4) {
        std::cout << menu_message;
        choice = Input_Int();
        if (choice < 1 || choice > 4) {
            std::cout << "\nError. Please enter a number between 1 and 6.\n\n";
            continue;
        }
        switch (choice) {
        case 1:
            TreeFun1();
            break;
        case 2:
            TreeFun3();
            break;
        case 3:
            TreeFun13();
            break;
        }
        std::cout << "\n";
    }

    std::cout << "Shut down..." << std::endl;
    return 0;
}