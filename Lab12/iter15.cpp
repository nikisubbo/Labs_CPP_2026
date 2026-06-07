#include "iter15.h"
#include "stl_utils.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <limits>
#include <random>

void iter15() {
    std::string name;
    std::cout << "Enter output filename: ";
    std::cin >> name;
    int count;
    std::cout << "How many numbers will you enter? ";
    std::cin >> count;
    std::vector<int> numbers;
    int method;
    std::cout << "Choose input method:\n1) Keyboard\n2) Random\n3) From file\nChoice: ";
    std::cin >> method;
    while (method < 1 || method > 3) {
        std::cout << "Invalid choice. Enter 1, 2, or 3: ";
        std::cin >> method;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (method == 1) {
        std::cout << "Enter " << count << " integers:\n";
        for (int i = 0; i < count; ++i) {
            int num;
            std::cin >> num;
            numbers.push_back(num);
        }
    }
    else if (method == 2) {
        std::cout << "Generating " << count << " random numbers:\n";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);
        for (int i = 0; i < count; ++i) {
            int num = dis(gen);
            numbers.push_back(num);
            std::cout << num << " ";
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
        int num;
        int read_count = 0;
        while (read_count < count && infile >> num) {
            numbers.push_back(num);
            read_count++;
        }
        infile.close();
        if (read_count < count) {
            std::cout << "Warning: File contained only " << read_count << " elements.\n";
        }
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (numbers.empty()) {
        std::cout << "The set of numbers is empty. The entry was not completed.\n";
        return;
    }
    std::ofstream file(name);
    if (!file.is_open()) {
        std::cerr << "Error. File is not open: " << name << "\n";
        return;
    }
    std::cout << "\nThe recording is performed by replacing 0 with 10 and adding two spaces...\n";
    std::replace_copy(
        numbers.begin(),
        numbers.end(),
        std::ostream_iterator<int>(file, "  "),
        0,
        10
    );
    file.close();
    std::cout << "Successfully written to " << name << "\n";
    std::cout << "\nContents of the file: \n";
    std::ifstream check_file(name);
    std::string line;
    if (check_file.is_open()) {
        std::getline(check_file, line);
        std::cout << line << "\n";
        check_file.close();
    }
}