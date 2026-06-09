#include "hemming.h"
#include "sup.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
HemmingCode::HemmingCode(const std::string& bits) {//констр: строка в вектор
    for (char c : bits) data.push_back(c - '0');
    m = (int)data.size();//информ биты
    r = 0;
    while ((1 << r) < m + r + 1) r++;//контр биты
    n = m + r;//длина кода
    code.assign(n, 0);
    errPos = 0;
}
void HemmingCode::printEmpty() const {//таблица до
    std::cout << "\n\t";
    for (int i = 1; i <= n; ++i) std::cout << std::setw(2) << i << " | ";
    std::cout << "\n\t";
    int idx = 0;
    for (int i = 1; i <= n; ++i) {
        if ((i & (i - 1)) == 0) std::cout << " _ | ";
        else std::cout << " " << data[idx++] << " | ";
    }
    std::cout << "\n";
}
void HemmingCode::calcControlBits() {//расч контр битов
    int idx = 0;
    for (int i = 1; i <= n; ++i) {
        if ((i & (i - 1)) == 0) continue;//пропуск степеней двойки
        code[i - 1] = data[idx++];
    }
    for (int p = 1; p <= n; p *= 2) {
        int sum = 0;
        for (int i = p; i <= n; ++i) {
            if ((i & p) && i != p) sum ^= code[i - 1];
        }
        code[p - 1] = sum;
    }
}
int HemmingCode::syndrome() const {//вычисление синдрома
    int syn = 0;
    for (int p = 1; p <= n; p *= 2) {
        int sum = 0;
        for (int i = p; i <= n; ++i) {
            if (i & p) sum ^= code[i - 1];
        }
        if (sum) syn += p;
    }
    return syn;
}
void HemmingCode::run() {//кодирование + синдром
    calcControlBits();
    errPos = syndrome();
}
void HemmingCode::insertError(int pos) {//внесение ошибки
    if (pos >= 1 && pos <= n) {
        code[pos - 1] ^= 1;
        errPos = syndrome();
    }
}
void HemmingCode::printFull() const {
    std::cout << "\nThe original message (" << m << " bit): ";
    for (int b : data) std::cout << b;
    std::cout << "\nControl bits: " << r;
    std::cout << "\nTotal code length: " << n << "\n";

    std::cout << "\nControl bits: ";
    for (int p = 1; p <= n; p *= 2) {
        std::cout << "\tC" << p << " = ";
        bool first = true;
        for (int i = p + 1; i <= n; ++i) {
            if (i & p) {
                if (!first) std::cout << " + ";
                std::cout << code[i - 1];
                first = false;
            }
        }
        std::cout << " = " << code[p - 1] << "\n";
    }
    std::cout << "\n\t";
    for (int i = 1; i <= n; ++i) std::cout << std::setw(2) << i << " | ";
    std::cout << "\n\t";
    for (int i = 0; i < n; ++i) std::cout << " " << code[i] << " | ";
    std::cout << "\n";
}
void HemmingCode::printSyndrome() const {
    std::cout << "\nControl bits: " << r;
    std::cout << "\nTotal code length: " << n << "\n";
    std::cout << "\n\t";
    for (int i = 1; i <= n; ++i) std::cout << std::setw(2) << i << " | ";
    std::cout << "\n\t";
    for (int i = 0; i < n; ++i) std::cout << " " << code[i] << " | ";
    std::cout << "\n";
    std::cout << "\nCalculation of syndromes: ";
    for (int p = 1; p <= n; p *= 2) {
        std::cout << "\ts" << p << " = ";
        int sum = 0;
        bool first = true;
        for (int i = p; i <= n; ++i) {
            if ((i & p) != 0) {
                if (!first) std::cout << " + ";
                std::cout << code[i - 1];
                sum ^= code[i - 1];
                first = false;
            }
        }
        std::cout << " = " << sum << "\n";

        std::cout << "\t\tv" << p << " = {";
        first = true;
        for (int i = p; i <= n; ++i) {
            if ((i & p) != 0) {
                if (!first) std::cout << ", ";
                std::cout << i;
                first = false;
            }
        }
        std::cout << "}\n";
    }
    if (errPos) {
        std::cout << "\nSindrom = " << errPos << " error in bit " << errPos << "\n";
        std::cout << "\nThe corrected word: ";
        for (int i = 0; i < n; ++i) {
            int val = code[i];
            if (i == errPos - 1) val ^= 1;
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
    else {
        std::cout << "\nSindrom = 0. There are no errors\n";
    }
}
void HowToFillHemming(std::string& msg) {
    int choice = 0;
    do {
        std::cout << "\nHow do you want to get the binary message?\n1)Keyboard\n2)Random\n3)File\n4)Back\nChoice: ";
        choice = Input_Int();
        if (choice < 1 || choice > 4) {
            std::cout << "Error. Enter correct number (1-4).\n";
            continue;
        }
        switch (choice) {
        case 1: {
            std::cout << "Enter binary message (only 0 and 1): ";
            std::cin >> msg;
            while (msg.empty() || msg.find_first_not_of("01") != std::string::npos) {
                std::cout << "Error. Only '0' and '1' are allowed. Try again: ";
                std::cin >> msg;
            }
            break;
        }
        case 2: {
            std::cout << "Enter the length of the message: ";
            int len = Input_Int();
            msg.clear();
            for (int i = 0; i < len; ++i) {
                msg += std::to_string(std::rand() % 2);
            }
            std::cout << "Random message: " << msg << "\n";
            break;
        }
        case 3: {
            std::string filename;
            std::cout << "Enter filename (e.g., data.txt): ";
            std::cin >> filename;
            std::ifstream infile(filename);
            if (!infile.is_open()) {
                std::cerr << "Error. File not open.\n";
                break;
            }
            infile >> msg;
            infile.close();
            if (msg.empty()) {
                std::cerr << "Error. File is empty.\n";
                break;
            }
            if (msg.find_first_not_of("01") != std::string::npos) {
                std::cerr << "Error. File must contain only 0 and 1.\n";
                msg.clear();
                break;
            }
            std::cout << "Message from file: " << msg << "\n";
            break;
        }
        }
    } while (choice != 4);
}