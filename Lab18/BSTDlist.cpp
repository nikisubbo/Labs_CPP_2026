#include <iostream>
#include <ctime>
#include <fstream>
#include "BSTDlist.h"
#include "sup.h"
Node::Node(int k) : key(k), left(nullptr), right(nullptr) {}//констр
int Node::get_key() const { return key; }//геттер ключ
Node* Node::get_left() const { return left; }//геттер лев
Node* Node::get_right() const { return right; }//геттер прав
void Node::set_left(Node* node) { left = node; }//сеттер лев
void Node::set_right(Node* node) { right = node; }//сеттер прав
BinaryTree::BinaryTree() : root(nullptr) {}//констр
BinaryTree::~BinaryTree() { clear(root); }//дестр
void BinaryTree::CompletionTree(const std::vector<int>& data) {//постр дерева из вектора
    for (int val : data) {
        if (!root) root = new Node(val);
        else add(root, val);
    }
}
void BinaryTree::add(Node* node, int val) {//добавл
    if (val == node->get_key()) return;//дубликаты игнор
    if (val < node->get_key()) {
        if (!node->get_left()) node->set_left(new Node(val));
        else add(node->get_left(), val);
    }
    else {
        if (!node->get_right()) node->set_right(new Node(val));
        else add(node->get_right(), val);
    }
}
void BinaryTree::show() const { print(root, 0); }
void BinaryTree::print(Node* node, int level) const {//вывод дерева боком
    if (!node) return;
    print(node->get_right(), level + 1);//сначала правое
    for (int i = 0; i < level; ++i)
        std::cout << "    ";
    std::cout << node->get_key() << "\n";
    print(node->get_left(), level + 1);
}
Node* BinaryTree::convert_to_list() {//преобр дерева в двусвязный список
    Node* head = nullptr;//нач списка
    Node* prev = nullptr;//послед узел
    convert(root, head, prev);
    root = nullptr;//дестр не удалял улы
    return head;
}
void BinaryTree::convert(Node* node, Node*& head, Node*& prev) {//рекурсивное преобр
    if (!node) return;
    convert(node->get_left(), head, prev);//сначала левое
    if (!head) head = node;//1 узел -начало списка
    if (prev) {
        node->set_left(prev);//левы1-предыдущ
        prev->set_right(node);//правый предыдуще-текущий
    }
    prev = node;//текущ = предыдущ
    convert(node->get_right(), head, prev);//потом правое
}
void BinaryTree::show_list(Node* head) const {//вывод списка
    Node* curr = head;
    while (curr) {
        std::cout << curr->get_key() << " <=> ";
        curr = curr->get_right();//идём по некст
    }
    std::cout << "null\n";
}
void BinaryTree::cleanup() {//очистка
    clear(root);
    root = nullptr;
}
void BinaryTree::clear(Node* node) {//удаление
    if (!node) return;
    clear(node->get_left());
    clear(node->get_right());
    delete node;
}
void HowToFill(BinaryTree& tree) {
    int choice = 0;
    do {
        std::cout << "\nHow do you want to fill the tree?\n1)Keyboard\n2)Rand\n3)File\n4)Back\nChoice: ";
        choice = Input_Int();
        if (choice < 1 || choice > 4) {
            std::cout << "Error. Enter correct number (1-4).\n";
            continue;
        }
        std::vector<int> data;
        switch (choice) {
        case 1: {
            std::cout << "Enter the number of items: ";
            int n = Input_Int();
            std::cout << "Enter " << n << " integer numbers:\n";
            for (int i = 0; i < n; i++) {
                data.push_back(Input_Int());
            }
            tree.CompletionTree(data);
            break;
        }
        case 2: {
            std::cout << "Enter the number of items: ";
            int n = Input_Int();
            for (int i = 0; i < n; i++) {
                data.push_back(std::rand() % 100);
            }
            tree.CompletionTree(data);
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
            int number3;
            while (infile >> number3) {
                data.push_back(number3);
            }
            infile.close();
            if (data.empty()) {
                std::cerr << "File is empty or contains no integers.\n";
            }
            else {
                tree.CompletionTree(data);
            }
            break;
        }
        } 
    } while (choice != 4);
}