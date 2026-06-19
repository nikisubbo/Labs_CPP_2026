#include "Assoc21.h"
#include <iostream>
#include <vector>
#include <map>      
#include <cmath>    
#include <limits>
void Assoc21() {
    int n;
    std::cout << "Enter the number of elements of vector V: ";
    while (!(std::cin >> n) || n <= 0) {
        std::cout << "Error. Enter integer number > 0: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::vector<int> V(n);
    std::cout << "Enter " << n << " integer numbers:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> V[i];
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::multimap<int, int> M;
    for (auto it = V.begin(); it != V.end(); ++it) {
        int last_digit = std::abs(*it) % 10;
        M.insert(std::make_pair(last_digit, *it));
    }
    std::cout << "\nResult: ";
    std::cout << "Key  : Value \n";
    for (auto it = M.begin(); it != M.end(); ++it) {
        std::cout << "      " << it->first << "      : " << it->second << "\n";
    }
}