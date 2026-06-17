#include "alg28.h"
#include "stl_utils.h"
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>
#include <limits>
#include <random>
#include <fstream>

void alg28() {
    int n;
    std::cout << "Enter an even number of elements in list L: ";
    std::cin >> n;
    while (n < 0 || n % 2 != 0) {
        std::cout << "Error: number must be even and >= 0. Enter again: ";
        std::cin >> n;
    }
    std::list<int> L;
    int method;
    std::cout << "Choose input method:\n1) Keyboard\n2) Random\n3) From file\nChoice: ";
    std::cin >> method;
    while (method < 1 || method > 3) {
        std::cout << "Invalid choice. Enter 1, 2, or 3: ";
        std::cin >> method;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (method == 1) {
        std::cout << "Enter " << n << " integers:\n";
        for (int i = 0; i < n; ++i) {
            int val;
            std::cin >> val;
            L.push_back(val);
        }
    }
    else if (method == 2) {
        std::cout << "Generating " << n << " random numbers:\n";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);
        for (int i = 0; i < n; ++i) {
            int val = dis(gen);
            L.push_back(val);
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
    else if (method == 3) {
        std::string filename;
        std::cout << "Enter source filename: ";
        std::cin >> filename;
        std::ifstream infile(filename);
        if (!infile.is_open()) {
            std::cerr << "Error. Source file not open: " << filename << "\n";
            return;
        }
        int val;
        int count = 0;
        while (count < n && infile >> val) {
            L.push_back(val);
            count++;
        }
        infile.close();
        if (count < n) {
            std::cout << "Warning: File contained only " << count << " elements.\n";
        }
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nBefore:\n";
    print_list("List L", L);
    if (L.empty()) {
        std::cout << "\nEmpty list\n";
        return;
    }
    auto mid = L.begin();
    std::advance(mid, L.size() / 2);
    auto is_not_positive = [](int x) { return x <= 0; };
    std::remove_copy_if(
        L.rbegin(),
        std::make_reverse_iterator(mid),
        std::front_inserter(L),
        is_not_positive
    );
    std::cout << "\nAfter:\n";
    print_list("List L", L);
}