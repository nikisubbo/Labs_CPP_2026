#include "alg60.h"
#include "stl_utils.h" 
#include <list>
#include <vector>
#include <algorithm>  
#include <numeric>     
#include <iterator>   
#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <random>

struct AverageFunctor {
    double operator()(double current, double previous) const {
        return (current + previous) / 2.0;
    }
};

void alg60() {
    int n;
    std::cout << "Enter the number of list elements L >=2: ";
    while (!(std::cin >> n) || n < 2) {
        std::cout << "Error. Enter integer number >= 2: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::list<double> L;
    int method;
    std::cout << "Choose input method:\n1) Keyboard\n2) Random\n3) From file\nChoice: ";
    std::cin >> method;
    while (method < 1 || method > 3) {
        std::cout << "Invalid choice. Enter 1, 2, or 3: ";
        std::cin >> method;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (method == 1) {
        std::cout << "Enter " << n << " numbers:\n";
        for (int i = 0; i < n; ++i) {
            double val;
            std::cin >> val;
            L.push_back(val);
        }
    }
    else if (method == 2) {
        std::cout << "Generating " << n << " random numbers:\n";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(1.0, 100.0);
        for (int i = 0; i < n; ++i) {
            double val = dis(gen);
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
        double val;
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
    std::cout << "\nBefore: ";
    std::cout << "List L: ";
    for (double x : L) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    std::vector<double> V;
    std::adjacent_difference(
        L.begin(),
        L.end(),
        std::back_inserter(V),
        AverageFunctor()
    );
    if (!V.empty()) {
        V.erase(V.begin());
    }
    std::cout << "\nAfter: ";
    std::cout << "Vector V (arithmetic means of pairs): ";
    for (double x : V) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}