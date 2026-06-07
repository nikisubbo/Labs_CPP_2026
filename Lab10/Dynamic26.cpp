#include <iostream>
#include "Dynamic26.h"
#include "queue.h"
#include "input.h"
void Dynamic26(Queue& q) {
	std::cout << "\nEnter N: ";
	int n;
	n = Input_Int();
	std::cout << "How do you want to define a set of numbers?\n1)Random\n2)Keyboard\n3)From file\nChoice:";
	int choice;
	while (true) {
		choice = Input_Int();
		if (choice == 1) {
			for (int i = 0; i < n; i++) {
				q.add(rand());
			}
			break;
		}
		else if (choice == 2) {
			for (int i = 0; i < n; i++) {
				q.add(Input_Int());
			}
			break;
		}
		else if (choice == 3) {
			std::cout << "FROMFILE\n";
			break;
		}
		else {
			std::cout << "Error. Enter number between 1 and 3: ";
			continue;
		}
	}
}