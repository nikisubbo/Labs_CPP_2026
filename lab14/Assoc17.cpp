#include "Assoc17.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
void Assoc17() {
    int n;
    std::cout << "Enter the number of words in vector V: ";
    std::cin >> n;
    std::vector<std::string> V(n);
    std::cout << "Enter " << n << " english words in capital letters:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> V[i];
    }
    std::map<char, int> M;
    for (auto it = V.begin(); it != V.end(); ++it) {
        M[(*it)[0]] += it->size();
    }
    std::cout << "\nResult: ";
    for (auto it = M.begin(); it != M.end(); ++it) {
        std::cout << it->first << it->second << " ";
    }
    std::cout << "\n";
}