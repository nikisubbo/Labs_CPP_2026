#include "seq12.h"
#include "stl_utils.h"
#include <iostream>   
#include <string>      
#include <vector>
#include <deque>
#include <list>
#include <iterator>   
#include <utility>   
#include <fstream>      
#include <limits>      
#include <random>       
void seq12() {
    int n = get_min_number("Enter the number of items >= 5: ", 5);
    std::cout << "\nChoose input method:\n";
    std::cout << "1) Keyboard\n";
    std::cout << "2) Random numbers\n";
    std::cout << "3) From file\n";
    std::cout << "Your choice (1-3): ";
    int method = 0;
    std::cin >> method;
    while (method < 1 || method > 3) {
        std::cout << "Invalid choice. Please enter 1, 2, or 3: ";
        std::cin >> method;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::vector<int> temp_data(n);

    if (method == 1) {
        std::cout << "Enter " << n << " integers separated by spaces:\n";
        for (int i = 0; i < n; ++i) {
            std::cin >> temp_data[i];
        }
    }
    else if (method == 2) {
        std::cout << "Generating " << n << " random numbers:\n";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);
        for (int i = 0; i < n; ++i) {
            temp_data[i] = dis(gen);
            std::cout << temp_data[i] << " ";
        }
        std::cout << "\n";
    }
    else if (method == 3) {
        std::string filename;
        std::cout << "Enter filename (e.g., data.txt): ";
        std::cin >> filename;
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error. File is not open: " << filename << "\n";
            return; 
        }
        int count = 0;
        std::cout << "Reading from file...\n";
        while (count < n && file >> temp_data[count]) {
            count++;
        }
        file.close();
        if (count < n) {
            std::cout << "Warning: File contained only " << count << " elements.\n";
        }
    }
    std::deque<int> D(temp_data.begin(), temp_data.end());
    std::list<int>  L(temp_data.begin(), temp_data.end());
    std::cout << "\nBefore: ";
    print_forward("Dek D", D);
    print_forward("List L", L);
    std::cout << "\nRevers: ";
    print_backward("Dek D", D);
    print_backward("List L", L);
    std::cout << "\nTask Execution: ";
    auto insert_pos = std::prev(L.end(), 5);
    auto d_first = D.rbegin();
    auto d_last = D.rbegin() + 5;
    L.insert(insert_pos, d_first, d_last);
    std::cout << "\nAfter: ";
    print_forward("Dek D", D);
    print_forward("List L", L);
}