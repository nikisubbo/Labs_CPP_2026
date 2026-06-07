#include "seq24.h"
#include "stl_utils.h"
#include <vector>
#include <list>
#include <iterator> 
#include <iostream>  
#include <string>       
#include <fstream>      
#include <limits>      
#include <random>       

void seq24() {
    int n1 = get_odd_number("Enter an odd number of elements for L1 (>= 1): ", 1);
    std::vector<int> temp1(n1);
    std::cout << "\nChoose input method for L1:\n";
    std::cout << "1) Keyboard\n2) Random numbers\n3) From file\n";
    std::cout << "Your choice (1-3): ";
    int method1 = 0;
    std::cin >> method1;
    while (method1 < 1 || method1 > 3) {
        std::cout << "Invalid choice. Please enter 1, 2, or 3: ";
        std::cin >> method1;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (method1 == 1) {
        std::cout << "Enter " << n1 << " integers for L1:\n";
        for (int i = 0; i < n1; ++i) {
            std::cin >> temp1[i];
        }
    }
    else if (method1 == 2) {
        std::cout << "Generating " << n1 << " random numbers for L1:\n";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);
        for (int i = 0; i < n1; ++i) {
            temp1[i] = dis(gen);
            std::cout << temp1[i] << " ";
        }
        std::cout << "\n";
    }
    else if (method1 == 3) {
        std::string filename;
        std::cout << "Enter filename for L1 (e.g., data1.txt): ";
        std::cin >> filename;
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error. File is not open: " << filename << "\n";
            return;
        }
        int count = 0;
        while (count < n1 && file >> temp1[count]) {
            count++;
        }
        file.close();
        if (count < n1) {
            std::cout << "Warning: File contained only " << count << " elements for L1.\n";
        }
    }
    int n2 = get_min_number("Enter the number of elements for L2 (>= 0): ", 0);
    std::vector<int> temp2(n2);

    if (n2 > 0) {
        std::cout << "\nChoose input method for L2:\n";
        std::cout << "1) Keyboard\n2) Random numbers\n3) From file\n";
        std::cout << "Your choice (1-3): ";
        int method2 = 0;
        std::cin >> method2;
        while (method2 < 1 || method2 > 3) {
            std::cout << "Invalid choice. Please enter 1, 2, or 3: ";
            std::cin >> method2;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (method2 == 1) {
            std::cout << "Enter " << n2 << " integers for L2:\n";
            for (int i = 0; i < n2; ++i) {
                std::cin >> temp2[i];
            }
        }
        else if (method2 == 2) {
            std::cout << "Generating " << n2 << " random numbers for L2:\n";
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(1, 100);
            for (int i = 0; i < n2; ++i) {
                temp2[i] = dis(gen);
                std::cout << temp2[i] << " ";
            }
            std::cout << "\n";
        }
        else if (method2 == 3) {
            std::string filename;
            std::cout << "Enter filename for L2 (e.g., data2.txt): ";
            std::cin >> filename;
            std::ifstream file(filename);
            if (!file.is_open()) {
                std::cerr << "Error. File is not open: " << filename << "\n";
                return;
            }
            int count = 0;
            while (count < n2 && file >> temp2[count]) {
                count++;
            }
            file.close();
            if (count < n2) {
                std::cout << "Warning: File contained only " << count << " elements for L2.\n";
            }
        }
    }
    std::list<int> L1(temp1.begin(), temp1.end());
    std::list<int> L2(temp2.begin(), temp2.end());
    std::cout << "\nBefore: ";
    print_forward("List L1", L1);
    print_forward("List L2", L2);
    std::cout << "\nTask Executionn ";
    int mid_index = L1.size() / 2;
    auto mid_it = std::next(L1.begin(), mid_index);
    L2.splice(L2.end(), L1, mid_it);
    std::cout << "\nAfter: ";
    print_forward("List L1", L1);
    print_forward("List L2", L2);
    std::cout << "\nRevers: ";
    print_backward("List L2", L2);
}