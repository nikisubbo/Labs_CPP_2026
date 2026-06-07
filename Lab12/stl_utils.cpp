#include "stl_utils.h"
#include <limits>
int get_even_number(const std::string& prompt) {
    int n;
    while (true) {
        std::cout << prompt;
        if (std::cin >> n) {
            if (n >= 2 && n % 2 == 0) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return n;
            }
            std::cout << "Error: the number must be even and not less than 2\n";
        }
        else {
            std::cout << "Error. Enter correct number\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
int get_min_number(const std::string& prompt, int min_val) {
    int n;
    while (true) {
        std::cout << prompt;
        if (std::cin >> n) {
            if (n >= min_val) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return n;
            }
            std::cout << "Error. Number >= " << min_val << "!\n";
        }
        else {
            std::cout << "Error. Enter coorect integer number\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
int get_odd_number(const std::string& prompt, int min_val) {
    int n;
    while (true) {
        std::cout << prompt;
        if (std::cin >> n) {
            if (n >= min_val && n % 2 != 0) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return n;
            }
            std::cout << "Error. Number >= " << min_val << " and odd\n";
        }
        else {
            std::cout << "Error. Enter coorect integer number\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}