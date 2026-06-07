#include "stl_utils.h"
#include <limits>
#include <list>
std::vector<int> get_vector_from_input(const std::string& prompt) {
    std::vector<int> vec;
    int n;
    std::cout << prompt;
    if (!(std::cin >> n) || n < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return vec;
    }
    std::cout << "Enter " << n << " integer numbers:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        vec.push_back(val);
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return vec;
}
void print_vector(const std::string& name, const std::vector<int>& v) {
    std::cout << name << ": ";
    if (v.empty()) {
        std::cout << "Empty";
    }
    else {
        for (int x : v) {
            std::cout << x << " ";
        }
    }
    std::cout << "\n";
}
std::list<int> get_even_list_from_input(const std::string& prompt) {
    std::list<int> lst;
    int n;
    while (true) {
        std::cout << prompt;
        if (std::cin >> n) {
            if (n >= 0 && n % 2 == 0) {
                break;
            }
            std::cout << "Error.The number of elements must be even and >= 0";
        }
        else {
            std::cout << "Error. Enter coorect number\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::cout << "Enter " << n << " integer number:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        lst.push_back(val);
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return lst;
}
std::vector<int> get_vector_min_size(const std::string& prompt, int min_size) {
    std::vector<int> vec;
    int n;
    while (true) {
        std::cout << prompt;
        if (std::cin >> n) {
            if (n >= min_size) {
                break;
            }
            std::cout << "Error: size must be >= " << min_size;
        }
        else {
            std::cout << "Error. Enter correct number";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::cout << "Enter " << n << " integer numbers:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        vec.push_back(val);
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return vec;
}
int get_positive_number(const std::string& prompt) {
    int n;
    while (true) {
        std::cout << prompt;
        if (std::cin >> n) {
            if (n > 0) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return n;
            }
            std::cout << "Ошибка: число должно быть строго больше 0!\n";
        }
        else {
            std::cout << "Ошибка: введите корректное целое число!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}