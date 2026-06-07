#include <iostream>
#include <limits> 
#include "Alg1.h"
#include "Alg28.h"
#include "Alg38.h"
#include "Alg60.h"
int main() {
    int choice = 0;
    std::string menu_message = "Menu:\n1)Alg1\n2)Alg28\n3)Agl38\n4)Alg60\n5)Exit\nSelect the desired task number: ";
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
            alg1();
            break;
        case 2:
            alg28();
            break;
        case 3:
            alg38();
            break;
        case 4:
            alg60();
            break;
        }
        std::cout << "\n";
    }

    std::cout << "Shut down..." << std::endl;
    return 0;
}