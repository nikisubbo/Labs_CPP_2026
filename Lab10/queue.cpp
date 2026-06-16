#include "queue.h"
#include <iostream>
#include <fstream>
#include "input.h"
#include "Dynamic26.h"

Queue::Queue() : head(nullptr), tail(nullptr) {}//конструктор
Queue::~Queue() {//деструктор
	while (head) {
		TNode* temp = head;
		head = head->next;
		delete temp;
	}
	tail = nullptr;
}
void Queue::add(int value) {//добавка в конец 
	TNode* new_node = new TNode(value, nullptr);
	if (!tail) {
		head = tail = new_node;
	}
	else {
		tail->next = new_node;
		tail = new_node;
	}
}
bool Queue::delq(int& value) {//удалить из начала
	if (!head) return false;
	value = head->data;
	TNode* temp = head;
	head = head->next;
	if (!head) tail = nullptr;
	delete temp;
	return true;
}
TNode* Queue::find(int value) const {//поиск по значению
	TNode* current = head;
	while (current) {
		if (current->data == value) return current;
		current = current->next;
	}
	return nullptr;
}
bool Queue::is_empty() const { return head == nullptr; }//пустой или нет
void Queue::print() const {//вывод
	if (!head) {
		std::cout << "пустая";
		return;
	}
	TNode* cur = head;
	std::cout << cur->data;
	cur = cur->next;
	while (cur) {
		std::cout << " -> " << cur->data;
		cur = cur->next;
	}
}
void Queue::QueueFromFile() {
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
		this->add(value); 
		count++;
	}
	file.close();
	std::cout << "Successfully loaded " << count << " elements from file into the queue.\n";
}
void Queue::fill_queue() {
	int n;
	int choice;
	std::cout << "How do you want to fill the queue?\n1)Random\n2)Keyboard\n3)From file\nChoice: ";
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
		QueueFromFile();
	}
	else {
		std::cout << "Invalid choice. Please enter 1, 2, or 3.\n";
	}
}
void queue_menu() {
	Queue q;
	int value_add;
	int value_pop;
	int value_find;
	int choice = -1;
	while (choice != 7) {
		std::cout << "\nYour queue: ";
		if (q.is_empty()) {
			std::cout << "Empty" << std::endl;
		}
		else {
			q.print();
		}
		std::cout << "\n0)Fill queue\n1)Add value to the end\n2)Delete value from the beginning\n3)Search\n4)Check top\n5)Check bottom\n6)Start Dynamic26\n7)Exit\nChoice: ";
		choice = Input_Int();
		if (choice < 0 || choice > 7) {
			std::cout << "Error. Enter a number between 1 and 7: ";
			choice = Input_Int();
			continue;
		}
		switch (choice) {
		case 0:
			q.fill_queue();
			break;
		case 1:
			std::cout << "Enter value: ";
			value_add = Input_Int();
			q.add(value_add);
			break;
		case 2:
			if (!q.is_empty()) {
				q.delq(value_pop);
				std::cout << "Delete: " << value_pop;
			}
			else {
				std::cout << "Empty\n";
			}
			break;
		case 3:
			if (!q.is_empty()) {
				std::cout << "Enter value: ";
				value_find = Input_Int();
				std::cout << "Value in queue" << q.find(value_find) << "\n";
			}
			else {
				std::cout << "Empty\n";
			}
			break;
		case 4:
			if (!q.is_empty()) {
				std::cout << "Aress top: " << q.get_top() << "value top: " << q.get_top()->data << "\n";
			}
			else {
				std::cout << "Empty\n";
			}
			break;
		case 5:
			if (!q.is_empty()) {
				std::cout << "Aress bottom: " << q.get_bottom() << "value bottom: " << q.get_bottom()->data << "\n";
			}
			else {
				std::cout << "Empty\n";
			}
			break;
		case 6:
			Dynamic26(q);
		}
	}
}