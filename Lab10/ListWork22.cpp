#include <iostream>
#include "input.h"
#include "list.h"
void ListWork22(LinkedList &l) {
	std::cout << "Enter M: ";
	int m;
	m = Input_Int();
	l.every_second(m);
}