#include <iostream>
#include "sup.h"
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
int main() {
    int choice = 0;
    std::string menu_message = "Menu:\n1)Task1\n2)Task2\n3)Task3\n4)Exit\nSelect the desired task number: ";
    while (choice != 4) {
        std::cout << menu_message;
        choice = Input_Int();
        if (choice < 1 || choice > 4) {
            std::cout << "\nError. Please enter a number between 1 and 6.\n\n";
            continue;
        }
        switch (choice) {
        case 1:
            Task1();
            break;
        case 2:
            Task2();
            break;
        case 3:
            
            break;
        }
        std::cout << "\n";
    }

    std::cout << "Shut down..." << std::endl;
    return 0;
}