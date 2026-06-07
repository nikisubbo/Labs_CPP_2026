#include "CircularList.h"
#include <fstream>
#include <iostream>
#include <locale>  
#include <windows.h>  
#include "ListWork67.h"
#include "input.h"
CircularList::CircularList() : head(nullptr) {}
CircularList::~CircularList() { clear(); }
CircularList::CircularList(const CircularList& other) : head(nullptr) {
	copy_from(other);
}
CircularList& CircularList::operator=(const CircularList& other) {
	if (this != &other) {
		clear();
		copy_from(other);
	}
	return *this;
}
void CircularList::clear() {
	if (!head) return;
	CNode* current = head;
	do {
		CNode* temp = current;
		current = current->next;
		delete temp;
	} while (current != head);
	head = nullptr;
}
void CircularList::copy_from(const CircularList& other) {
	if (!other.head) {
		head = nullptr;
		return;
	}
	head = new CNode(other.head->data);
	CNode* current = head;
	CNode* other_current = other.head->next;
	while (other_current != other.head) {
		current->next = new CNode(other_current->data);
		current = current->next;
		other_current = other_current->next;
	}
	current->next = head;
}
void CircularList::add(int value) {
	CNode* new_node = new CNode(value);
	if (!head) {
		head = new_node;
		head->next = head;
	}
	else {
		CNode* tail = head;
		while (tail->next != head) tail = tail->next;
		tail->next = new_node;
		new_node->next = head;
	}
}
bool CircularList::is_empty() const { return head == nullptr; }
void CircularList::print() const {
	if (!head) {
		std::cout << "Empty";
		return;
	}
	CNode* current = head;
	do {
		std::cout << current->data;
		current = current->next;
		if (current != head) std::cout << " -> ";
	} while (current != head);
}
CNode* CircularList::find(int value) const {
	if (!head) return nullptr;
	CNode* current = head;
	do {
		if (current->data == value) return current;
		current = current->next;
	} while (current != head);
	return nullptr;
}
int CircularList::size() const {
	if (!head) return 0;

	int count = 0;
	CNode* current = head;
	do {
		count++;
		current = current->next;
	} while (current != head);

	return count;
}
bool CircularList::remove(int value) {
	if (!head) return false;
	if (head->next == head) {
		if (head->data == value) {
			delete head;
			head = nullptr;
			return true;
		}
		return false;
	}
	CNode* current = head;
	CNode* prev = nullptr;
	do {
		if (current->data == value) {
			if (current == head) {
				CNode* tail = head;
				while (tail->next != head) tail = tail->next;
				tail->next = head->next;
				head = head->next;
			}
			else {
				prev->next = current->next;
			}
			delete current;
			return true;
		}
		prev = current;
		current = current->next;
	} while (current != head);
	return false;
}
void CircularList::ClistFromFile() {
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
		add(value);
		count++;
	}
	file.close();
	std::cout << "Successfully loaded " << count << " elements from file.\n";
}
void CircularList::fill_clist() {
	int n;
	int choice;
	std::cout << "How do you want to fill the stack?\n1)Random\n2)Keyboard\n3)From file\nChoice: ";
	choice = Input_Int();
	if (choice == 1) {
		std::cout << "How many numbers will you fill?\nEnter the number: ";
		n = Input_Int();
		for (int i = 0; i < n; i++) {
			int number = rand();
			add(number);
		}
		std::cout << "Stack filled with " << n << " random numbers.\n";
	}
	else if (choice == 2) {
		std::cout << "How many numbers will you fill?\nEnter the number: ";
		n = Input_Int();
		for (int i = 0; i < n; i++) {
			std::cout << "Enter element " << i + 1 << ": ";
			int number = Input_Int();
			add(number);
		}
		std::cout << "Stack filled with " << n << " elements.\n";
	}
	else if (choice == 3) {
		ClistFromFile();
	}
	else {
		std::cout << "Invalid choice. Please enter 1, 2, or 3.\n";
	}
}
void clist_menu() {
	CircularList s;
	int value_add;
	int value_pop;
	int value_find;
	int choice = -1;
	while (choice != 7) {
		std::cout << "\nYour CList: ";
		if (s.is_empty()) {
			std::cout << "Empty" << std::endl;
		}
		else {
			s.print();
		}
		std::cout << "\n0)Fill CList\n1)Add value\n2)Delete value\n3)Search\n4)Check top\n5)Start ListWork67\n6)Task3\n7)Exit\nChoice: ";
		choice = Input_Int();
		if (choice < 0 || choice > 7) {
			std::cout << "Error. Enter a number between 0 and 7: ";
			choice = Input_Int();
			continue;
		}
		switch (choice) {
		case 0:
			s.fill_clist();
			break;
		case 1:
			std::cout << "Enter value: ";
			value_add = Input_Int();
			s.add(value_add);
			break;
		case 2:
			if (!s.is_empty()) {
				std::cout << "Enter value for delete: ";
				value_pop = Input_Int();
				s.remove(value_pop);
				std::cout << "Delete " << value_pop;
			}
			else {
				std::cout << "Empty\n";
			}
			break;
		case 3:
			if (!s.is_empty()) {
				std::cout << "Enter value: ";
				value_find = Input_Int();
				std::cout << s.find(value_find) << "\n";
			}
			else {
				std::cout << "Empty\n";
			}
			break;
		case 4:
			if (!s.is_empty()) {
				std::cout << "Aress head: " << s.get_head() << "value top: " << s.get_head()->data;
			}
			else {
				std::cout << "Empty\n";
			}
			break;
		case 5: {
			std::string filename = "ListWork67.txt";
			s.ListWork67(filename);
			break;
		}
		case 6:
			s.Task3();
			break;
		}
	}
}