#include "Graph1.h"
#include "sup.h"
#include <iostream>
void Graf1() {
    std::cout << "\nHow to create a graph?\n";
    std::cout << "1)From keyboard\n2)Randomly\n3)From file\nChoose: ";
    int choose = Input_Int();
    while (choose < 1 || choose > 3) {
        std::cout << "\nError. Let's try again: ";
        choose = Input_Int();
    }
    Graph g;
    if (choose == 1) g = Graph::fromKeyboard();
    else if (choose == 2) g = Graph::fromRandom();
    else g = Graph::fromFile();

    if (g.getVertexCount() == 0) {
        std::cout << "\nError: failed to load graph!\n";
        std::cin.get();
        return;
    }
    g.printMatrix();
    g.printDegrees();
    std::cout << "  /\\_/\\\n" << " ( V.V )\n" << "  > ^ <\n";
}