#include <iostream>
#include "Hemming.h"
#include "sup.h"
void Task1() {
	std::cout << "Task1. Hemming code.\n";
	std::string message;
	HowToFillHemming(message);
	HemmingCode h(message);
	h.printEmpty();
	std::cout << "\nAfter calculating the control bits: ";
	h.run();
	h.printFull();
	std::cout << "Enter the bit number for the mistake: ";
	int error;
	error = Input_Int();
	while (error < 1 || error > h.get_n()) {
		std::cout << "\nError. 0 to 1 " << h.get_n() << ": ";
		error = Input_Int();
	}
	h.insertError(error);
	std::cout << "\n\After making an error: ";
	h.printSyndrome();
	std::cin.get();
}