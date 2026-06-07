#include "Seq7.h"
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
#include <cstdlib>      

void seq7() {
    int n = get_even_number("Enter the even number of elements: ");
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
        for (int i = 0; i < n; ++i) {
            temp_data[i] = rand() % 100; 
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
        else {
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
    }
    std::vector<int> V(temp_data.begin(), temp_data.end());
    std::deque<int>  D(temp_data.begin(), temp_data.end());
    std::list<int>   L(temp_data.begin(), temp_data.end());

    std::cout << "\nBefore: ";
    print_forward("Vector V", V);
    print_forward("Dek D", D);
    print_forward("List L", L);
    std::cout << "\nRbegin/rend: ";
    print_backward("Vector V", V);
    int mid1 = n / 2 - 1;
    int mid2 = n / 2;
    std::cout << "\nSwap: \n";
    std::cout << "Swap position " << (mid1 + 1) << " and " << (mid2 + 1) << "\n";
    std::swap(V[mid1], V[mid2]);
    std::swap(D[mid1], D[mid2]);
    auto it1 = std::next(L.begin(), mid1);
    auto it2 = std::next(L.begin(), mid2);
    std::swap(*it1, *it2);
    std::cout << "\nAfter: \n";
    print_forward("Vector V", V);
    print_forward("Dek D", D);
    print_forward("List L", L);
}