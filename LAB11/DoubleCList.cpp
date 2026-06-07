#include "DoubleClist.h"
#include "input.h"
#include <fstream>
#include <iostream>
#include <string>
#include "ListWork42.h"
CircularDoublyList::CircularDoublyList() : head(nullptr) {}
CircularDoublyList::~CircularDoublyList() {
    clear();
}
CircularDoublyList::CircularDoublyList(const CircularDoublyList& other) : head(nullptr) {
    copy_from(other);
}
CircularDoublyList& CircularDoublyList::operator=(const CircularDoublyList& other) {
    if (this != &other) {
        clear();
        copy_from(other);
    }
    return *this;
}
void CircularDoublyList::clear() {
    if (!head) return;
    Node* current = head;
    do {
        Node* temp = current;
        current = current->next;
        delete temp;
    } while (current != head);
    head = nullptr;
}
void CircularDoublyList::copy_from(const CircularDoublyList& other) {
    if (!other.head) {
        head = nullptr;
        return;
    }
    head = new Node(other.head->data);
    Node* current = head;
    Node* other_current = other.head->next;
    while (other_current != other.head) {
        current->next = new Node(other_current->data, nullptr, current);
        current = current->next;
        other_current = other_current->next;
    }
    current->next = head;
    head->prev = current;
}
void CircularDoublyList::add(int value) {
    Node* new_node = new Node(value);
    if (!head) {
        head = new_node;
        head->next = head;
        head->prev = head;
    }
    else {
        Node* tail = head->prev;
        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = head;
        head->prev = new_node;
    }
}
bool CircularDoublyList::is_empty() const { return head == nullptr; }
void CircularDoublyList::print() const {
    if (!head) {
        std::cout << "Empty";
        return;
    }
    Node* current = head;
    do {
        std::cout << current->data;
        current = current->next;
        if (current != head) std::cout << " <-> ";
    } while (current != head);
}
Node* CircularDoublyList::find(int value) const {
    if (!head) return nullptr;
    Node* current = head;
    do {
        if (current->data == value) return current;
        current = current->next;
    } while (current != head);
    return nullptr;
}
Node* CircularDoublyList::listwork42() {
    if (!head) {
        std::cout << "Empty list.\n";
        return nullptr;
    }
    bool changed = true;
    while (changed && head) {
        changed = false;
        Node* current = head;
        Node* start = head;
        do {
            Node* next_node = current->next; 
            if (current->next == current->prev) {
                if (current->next == current) {
                    delete current;
                    head = nullptr;
                    changed = true;
                    break;
                }
                current->prev->next = current->next;
                current->next->prev = current->prev;
                if (current == head) {
                    head = next_node;
                }
                delete current;
                changed = true;
            }
            current = next_node;
        } while (head && current != start);
    }
    if (!head) {
        std::cout << "\nAll element delete.\n";
        return nullptr;
    }
    return head->prev;
}
bool CircularDoublyList::remove(Node* target) {
    if (!target || !head) return false;
    if (head->next == head) {
        delete head;
        head = nullptr;
        return true;
    }
    target->prev->next = target->next;
    target->next->prev = target->prev;
    if (target == head) {
        head = target->next;
    }
    delete target;
    return true;
}
void CircularDoublyList::DobuleClistFromFile(){
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;
    std::ifstream file(filename);  // ← ОБЪЯВЛЕНИЕ file
    if (!file.is_open()) {
        std::cout << "Error: Could not open file '" << filename << "'.\n";
        return;
    }
    int value;
    int count = 0;
    while (file >> value) {
        add(value);
        count++;
    }
    file.close();
    std::cout << "Successfully loaded " << count << " elements from file.\n";
}
void CircularDoublyList::fill_Dclist() {
    int n;
    int choice;
    std::cout << "How do you want to fill the circular doubly list?\n"
        << "1)Random\n2)Keyboard\n3)From file\nChoice: ";
    choice = Input_Int();

    if (choice == 1) {
        std::cout << "How many numbers will you fill?\nEnter the number: ";
        n = Input_Int();
        for (int i = 0; i < n; i++) {
            add(rand());
        }
        std::cout << "List filled with " << n << " random numbers.\n";
    }
    else if (choice == 2) {
        std::cout << "How many numbers will you fill?\nEnter the number: ";
        n = Input_Int();
        for (int i = 0; i < n; i++) {
            std::cout << "Enter element " << i + 1 << ": ";
            add(Input_Int());
        }
        std::cout << "List filled with " << n << " elements.\n";
    }
    else if (choice == 3) {
        DobuleClistFromFile();
    }
    else {
        std::cout << "Invalid choice. Please enter 1, 2, or 3.\n";
    }
}
void Dclist_menu() {
    CircularDoublyList s;
    int value_add;
    int value_find;
    int choice = -1;
    while (choice != 6) {
        std::cout << "\nYour Circular Doubly List: ";
        if (s.is_empty()) {
            std::cout << "Empty";
        }
        else {
            s.print();
        }
        std::cout << "\n0)Fill list\n1)Add value\n2)Delete value\n3)Search\n4)Check head\n5)ListWork42\n6)Exit\nChoice: ";
        choice = Input_Int();
        if (choice == 6) {
            std::cout << "Exiting...\n";
            break;
        }
        if (choice < 0 || choice > 6) {
            std::cout << "Error. Enter a number between 0 and 6.\n";
            continue;
        }
        switch (choice) {
        case 0:
            s.fill_Dclist();
            break;
        case 1:
            std::cout << "Enter value: ";
            value_add = Input_Int();
            s.add(value_add);
            break;
        case 2:
            if (!s.is_empty()) {
                std::cout << "Enter value for delete: ";
                int value_pop = Input_Int();
                Node* target = s.find(value_pop);
                if (target) {
                    s.remove(target);
                    std::cout << "Deleted " << value_pop << "\n";
                }
                else {
                    std::cout << "Value " << value_pop << " not found.\n";
                }
            }
            else {
                std::cout << "Empty\n";
            }
            break;

        case 3:
            if (!s.is_empty()) {
                std::cout << "Enter value: ";
                value_find = Input_Int();
                Node* found = s.find(value_find);
                if (found) {
                    std::cout << "Found at address: " << found
                        << ", value: " << found->data << "\n";
                }
                else {
                    std::cout << "Value not found.\n";
                }
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
            ListWork42(s);
        }
        }
    }
}