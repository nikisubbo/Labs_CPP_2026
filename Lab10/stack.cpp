#include "stack.h"
#include "input.h"
#include <fstream>
#include <iostream>
#include "Dynamic4.h"

Stack::Stack() { top = nullptr; }//конструктор по умолчанию

Stack::Stack(const Stack& other) { 
	top = nullptr; copy(other);
}//копирования

Stack::~Stack() { clear(); }//деструктор

Stack& Stack::operator=(const Stack& other) {// присваивание
	if (this != &other) {
		clear();
		copy(other);
	}
	return *this;
}
void Stack::add(int value) {//добавить
	Node* new_node = new Node;
	new_node->data = value;
	new_node->next = top;
	top = new_node;
}
bool Stack::pop(int& value) {//удалить
	if (top == nullptr) return false;
	value = top->data;
	Node* temp = top;
	top = top->next;
	delete temp;
	return true;
}
bool Stack::peek(int& value) const {//посмотреть вершину
	if (top == nullptr) return false;
	value = top->data;
	return true;
}
Node* Stack::find(int value) const {//поиск по значению
	Node* current = top;
	while (current) {
		if (current->data == value) return current;
		current = current->next;
	}
	return nullptr;
}
bool Stack::is_empty() const { return top == nullptr; }//пустой или нет

Node* Stack::get_top() const { return top; }//указатель на вершину

void Stack::print() const {//вывод
	if (top == nullptr) {
		std::cout << "Empty stack";
		return;
	}
	Node* current = top;
	while (current != nullptr) {
		std::cout << current->data;
		if (current->next != nullptr) {
			std::cout << " -> ";
		}
		current = current->next;
	}
}
void Stack::clear() {//очистка
	while (top != nullptr) {
		Node* temp = top;
		top = top->next;
		delete temp;
	}
}
void Stack::StackFromFile() {
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
void Stack::copy(const Stack& other) {
	if (other.top == nullptr) {
		top = nullptr;
		return;
	}
	Node* temp = nullptr;
	Node* current = other.top;
	while (current != nullptr) {
		Node* new_node = new Node;
		new_node->data = current->data;
		new_node->next = temp;
		temp = new_node;
		current = current->next;
	}
	top = nullptr;
	current = temp;
	while (current != nullptr) {
		Node* next_node = current->next; 
		current->next = top;            
		top = current;                   
		current = next_node;             
	}
}
void stack_menu() {
	Stack s;
	int value_add;
	int value_pop;
	int value_find;
	int choice = -1;
	while (choice != 6) {
		std::cout << "\nYour stack: ";
		if (s.is_empty()) {
			std::cout << "Empty" << std::endl;
		}
		else {
			s.print();
		}
		std::cout << "\n0)Fill stack\n1)Add value\n2)Delete value\n3)Search\n4)Check top\n5)Start Dynamic4\n6)Exit\nChoice: ";
		choice = Input_Int();
		if (choice < 0 || choice > 6) {
			std::cout << "Error. Enter a number between 1 and 6: ";
			choice = Input_Int();
			continue;
		}
		switch (choice) {
		case 0:
			s.fill_stack();
			break;
		case 1:
			std::cout << "Enter value: ";
			value_add = Input_Int();
			s.add(value_add);
			break;
		case 2:
			if (!s.is_empty()) {
				s.pop(value_pop);
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
				std::cout << "Aress top: " << s.get_top() << "value top: " << s.get_top()->data;
			}
			else {
				std::cout << "Empty\n";
			}
			break;
		case 5:
			Dynamic4(s);
		}
	}
}
void Stack::fill_stack() {
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
		StackFromFile();
	}
	else {
		std::cout << "Invalid choice. Please enter 1, 2, or 3.\n";
	}
}