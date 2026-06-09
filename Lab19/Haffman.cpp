#include "Haffman.h"
#include "sup.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <fstream>
HaffmanNode::HaffmanNode(char sym, int freq) : sym(sym), freq(freq), left(nullptr), right(nullptr) {}
char HaffmanNode::get_sym() const { return sym; }
int HaffmanNode::get_freq() const { return freq; }
HaffmanNode* HaffmanNode::get_left() const { return left; }
HaffmanNode* HaffmanNode::get_right() const { return right; }
void HaffmanNode::set_left(HaffmanNode* node) { left = node; }
void HaffmanNode::set_right(HaffmanNode* node) { right = node; }
bool NodeComparator::operator()(HaffmanNode* a, HaffmanNode* b) const {
    return a->get_freq() > b->get_freq();
}
HaffmanCoder::HaffmanCoder(const std::string& txt) : text(txt), root(nullptr), totalBits(0) {
    for (char c : text) freqs[c]++;
}
HaffmanCoder::~HaffmanCoder() { deleteTree(root); }
void HaffmanCoder::deleteTree(HaffmanNode* node) {
    if (!node) return;
    deleteTree(node->get_left());
    deleteTree(node->get_right());
    delete node;
}
void HaffmanCoder::buildTree() {
    std::priority_queue<HaffmanNode*, std::vector<HaffmanNode*>, NodeComparator> pq;
    for (auto& pair : freqs) pq.push(new HaffmanNode(pair.first, pair.second));
    while (pq.size() > 1) {
        HaffmanNode* l = pq.top(); pq.pop();
        HaffmanNode* r = pq.top(); pq.pop();
        HaffmanNode* p = new HaffmanNode(0, l->get_freq() + r->get_freq());
        p->set_left(l);
        p->set_right(r);
        pq.push(p);
    }
    if (!pq.empty()) root = pq.top();
}
void HaffmanCoder::generateCodes(HaffmanNode* node, std::string code) {
    if (!node) return;
    if (!node->get_left() && !node->get_right()) {
        codes[node->get_sym()] = code.empty() ? "0" : code;
        return;
    }
    generateCodes(node->get_left(), code + "0");
    generateCodes(node->get_right(), code + "1");
}
void HaffmanCoder::encode() {
    buildTree();
    generateCodes(root, "");
    totalBits = 0;
    encodedBits.clear();
    for (char c : text) {
        std::string code = codes[c];
        totalBits += (int)code.length();
        encodedBits += code;
    }
}
void HaffmanCoder::printTreeRecursive(HaffmanNode* node, int level) const {
    if (!node) return;
    printTreeRecursive(node->get_right(), level + 1);
    for (int i = 0; i < level; ++i) std::cout << "    ";
    std::cout << node->get_freq() << ":< ";
    if (node->get_sym() != 0) std::cout << "'" << node->get_sym() << "'";
    std::cout << "\n";
    printTreeRecursive(node->get_left(), level + 1);
}
void HaffmanCoder::printTree() const {
    std::cout << "\n\tTree: \n";
    if (root) printTreeRecursive(root, 0);
}
void HaffmanCoder::printTable() const {
    std::cout << "\n\tSymbol | Frequency | Haffman code:\n";
    std::vector<std::pair<char, int>> sortedFreq(freqs.begin(), freqs.end());
    std::sort(sortedFreq.begin(), sortedFreq.end(),
        [](const auto& a, const auto& b) { return a.second > b.second; });
    for (const auto& pair : sortedFreq) {
        char sym = pair.first;
        int freq = pair.second;
        std::string code = codes.at(sym);
        std::cout << "\t  '" << sym << "'   |   " << freq << "   |   " << code << "\n";
    }
}
void HaffmanCoder::printStats() const {
    int unique = (int)freqs.size();
    int len = (int)text.length();
    int bitsPerSym = (unique > 1) ? (int)std::ceil(std::log2(unique)) : 1;
    int uniformBits = len * bitsPerSym;
    int huffmanBits = totalBits;
    int diff = uniformBits - huffmanBits;
    std::cout << "\nSize Comparison;)\n";
    std::cout << "Unique characters: " << unique << "\n";
    std::cout << "Bits per character (evenly distributed): " << bitsPerSym << "\n";
    std::cout << "Uniform: " << uniformBits << " bit\n";
    std::cout << "The Haffman Code: " << huffmanBits << " bit\n";
    std::cout << "Difference: " << diff << " bit\n";
}
std::string HaffmanCoder::decodeFromTree(const std::string& bits) const {
    std::string result;
    HaffmanNode* curr = root;
    for (char bit : bits) {
        if (bit == '0') curr = curr->get_left();
        else curr = curr->get_right();
        if (!curr->get_left() && !curr->get_right()) {
            result += curr->get_sym();
            curr = root;
        }
    }
    return result;
}
std::string HaffmanCoder::decode(const std::string& bits, HaffmanNode* treeRoot) {
    std::string result;
    HaffmanNode* current = treeRoot;
    for (char bit : bits) {
        if (bit == '0') current = current->get_left();
        else current = current->get_right();
        if (!current->get_left() && !current->get_right()) {
            result += current->get_sym();
            current = treeRoot;
        }
    }
    return result;
}
void HaffmanCoder::printEncodedBits() const {
    std::cout << "\nEncoded bit string:\n";
    for (size_t i = 0; i < encodedBits.length(); ++i) {
        std::cout << encodedBits[i];
        if ((i + 1) % 8 == 0) std::cout << " ";
    }
    std::cout << "\n";
}
void HowToFillHaffman(std::string& msg) {
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