#include "alg38.h"
#include "stl_utils.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <limits>
#include <random>
#include <fstream>

void alg38() {
    int n;
    std::cout << "Enter vector size >= 3: ";
    std::cin >> n;
    while (n < 3) {
        std::cout << "Error: size must be >= 3. Enter again: ";
        std::cin >> n;
    }
    std::vector<int> V;
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
            V.push_back(val);
        }
    }
    else if (method == 2) {
        std::cout << "Generating " << n << " random numbers:\n";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);
        for (int i = 0; i < n; ++i) {
            int val = dis(gen);
            V.push_back(val);
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
            V.push_back(val);
            count++;
        }
        infile.close();
        if (count < n) {
            std::cout << "Warning: File contained only " << count << " elements.\n";
        }
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nBefore: ";
    print_vector("Vector V", V);
    std::partial_sort(V.begin(), V.begin() + 3, V.end(), std::greater<int>());
    std::cout << "\nAfter: ";
    std::copy(
        V.begin(),
        V.begin() + 3,
        std::ostream_iterator<int>(std::cout, " ")
    );
    std::cout << "\n";
}