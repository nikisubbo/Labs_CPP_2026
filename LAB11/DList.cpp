#include "Dlist.h"
#include "input.h"
#include "ListWork63.h"
#include "ListWork46.h"
#include <fstream>
#include <iostream>
DoublyList::DoublyList() : head(nullptr), tail(nullptr) {}
DoublyList::~DoublyList() { clear(); }
DoublyList::DoublyList(const DoublyList& other) : head(nullptr), tail(nullptr) {
    copy_from(other);
}
DoublyList& DoublyList::operator=(const DoublyList& other) {
    if (this != &other) {
        clear();
        copy_from(other);
    }
    return *this;
}
void DoublyList::clear() {
    while (head) {
        DNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}
void DoublyList::copy_from(const DoublyList& other) {
    DNode* current = other.head;
    while (current) {
        add_back(current->data);
        current = current->next;
    }
}
void DoublyList::add_back(int value) {
    DNode* new_node = new DNode(value);
    if (!head) {
        head = tail = new_node;
    }
    else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}
void DoublyList::print() const {
    if (!head) {
        std::cout << "пустой";
        return;
    }
    DNode* current = head;
    while (current) {
        std::cout << current->data;
        current = current->next;
        if (current) std::cout << " <-> ";
    }
}
bool DoublyList::is_empty() const {
    return head == nullptr;
}
void DoublyList::disconnect() {
    head = nullptr;
    tail = nullptr;
}
void DoublyList::add_front(int value) {
    DNode* new_node = new DNode(value);
    if (!head) {
        head = tail = new_node;
    }
    else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}
bool DoublyList::remove(int value) {
    DNode* current = head;
    while (current) {
        if (current->data == value) {
            if (current == head && current == tail) {
                head = tail = nullptr;
            }
            else if (current == head) {
                head = head->next;
                head->prev = nullptr;
            }
            else if (current == tail) {
                tail = tail->prev;
                tail->next = nullptr;
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            return true;
        }
        current = current->next;
    }
    return false;
}

DNode* DoublyList::find(int value) const {
    DNode* current = head;
    while (current) {
        if (current->data == value) return current;
        current = current->next;
    }
    return nullptr;
}

DNode* create_barrier_and_link(DNode* head, DNode* tail) {
    DNode* barrier = new DNode(0);
    if (head == nullptr) {
        barrier->next = barrier;
        barrier->prev = barrier;
    }
    else {
        barrier->next = head;
        barrier->prev = tail;
        head->prev = barrier;
        tail->next = barrier;
    }

    return barrier;
}
int DoublyList::remove_back() {
    if (!tail) {
        throw std::runtime_error("List is empty");
    }
    int value = tail->data;
    DNode* to_delete = tail;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }

    delete to_delete;
    return value;
}
void DoublyList::DobuleFromFile() {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file '" << filename << "'.\n";
        return;
    }
    int value;
    int count = 0;
    while (file >> value) {
        add_front(value);
        count++;
    }
    file.close();
    std::cout << "Successfully loaded " << count << " elements from file.\n";
}
void DoublyList::fill_Dlist() {
    int n;
    int choice;
    std::cout << "How do you want to fill the doubly list?\n"
        << "1)Random\n2)Keyboard\n3)From file\nChoice: ";
    choice = Input_Int();

    if (choice == 1) {
        std::cout << "How many numbers will you fill?\nEnter the number: ";
        n = Input_Int();
        for (int i = 0; i < n; i++) {
            add_back(rand());
        }
        std::cout << "List filled with " << n << " random numbers.\n";
    }
    else if (choice == 2) {
        std::cout << "How many numbers will you fill?\nEnter the number: ";
        n = Input_Int();
        for (int i = 0; i < n; i++) {
            std::cout << "Enter element " << i + 1 << ": ";
            add_back(Input_Int());
        }
        std::cout << "List filled with " << n << " elements.\n";
    }
    else if (choice == 3) {
        DobuleFromFile();
    }
    else {
        std::cout << "Invalid choice. Please enter 1, 2, or 3.\n";
    }
}
void Dlist_menu() {
    DoublyList s;
    int value_add;
    int value_find;
    int choice = -1;
    while (choice != 6) {
        std::cout << "\nYour Doubly List: ";
        if (s.is_empty()) {
            std::cout << "Empty";
        }
        else {
            s.print();
        }
        std::cout << "\n0)Fill list\n1)Add value\n2)Delete value\n3)Search\n4)Check head\n5)ListWork63\n6)ListWork46\n7)Exit\nChoice: ";
        choice = Input_Int();
        if (choice == 7) {
            std::cout << "Exiting...\n";
            break;
        }
        if (choice < 0 || choice > 7) {
            std::cout << "Error. Enter a number between 0 and 7.\n";
            continue;
        }
        switch (choice) {
        case 0:
            s.fill_Dlist();
            break;
        case 1:
            std::cout << "Enter value: ";
            value_add = Input_Int();
            s.add_back(value_add);
            break;
        case 2:
            if (!s.is_empty()) {
                std::cout << "Enter value for delete: ";
                int value_pop = Input_Int();
                s.remove(value_pop);

            }
            else {
                std::cout << "Empty\n";
            }
            break;

        case 3:
            if (!s.is_empty()) {
                std::cout << "Enter value: ";
                value_find = Input_Int();
                s.find(value_find);
            }
            else {
                std::cout << "Empty\n";
            }
            break;

        case 4:
            if (!s.is_empty()) {
                std::cout << "Head address: " << s.get_head()
                    << ", value: " << s.get_head()->data << "\n";
            }
            else {
                std::cout << "Empty\n";
            }
            break;
        case 5: {
            ListWork63(s);
            break;
        case 6: 
            ListWork46(s);
            break;
        }
        }
    }
}