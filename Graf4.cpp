#include "Graph4.h"
#include "sup.h"
#include <iostream>
void Graf4() {
    std::cout << "\nHow to create a graph?\n";
    std::cout << "1)From keyboard\n2)Randomly\n3)From file\nChoose: ";
    int choose = Input_Int();
    while (choose < 1 || choose > 3) {
        std::cout << "\nError. Let's try again: ";
        choose = Input_Int();
    }
    Graph4 g;
    if (choose == 1) g = Graph4::fromKeyboard();
    else if (choose == 2) g = Graph4::fromRandom();
    else g = Graph4::fromFile();

    if (g.getVertexCount() == 0) {
        std::cout << "\n\tError: failed to load graph!\n";
        std::cin.get();
        return;
    }
    std::cout << "\n\tGraph loaded! Vertices: " << g.getVertexCount() << "\n";
    g.printMatrix();
    std::cout << ("\n\tEnter the starting vertex (1-" + std::to_string(g.getVertexCount()) + "): ");
    int start = Input_Int();
    g.printBFS(start);
    std::cout << "  /\\_/\\\n" << " ( V.V )\n" << "  > ^ <\n";
}