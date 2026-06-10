#include "Graph8.h"
#include "sup.h"
#include <iostream>
void Graf8() {
    std::cout << "\nHow to create a graph?\n";
    std::cout << "1)From keyboard\n2)Randomly\n3)From file\nChoose: ";
    int choose = Input_Int();
    while (choose < 1 || choose > 3) {
        std::cout << "\nError. Let's try again: ";
        choose = Input_Int();
    }
    Graph8 g;
    if (choose == 1) g = Graph8::fromKeyboard();
    else if (choose == 2) g = Graph8::fromRandom();
    else g = Graph8::fromFile();

    if (g.getVertexCount() == 0) {
        std::cout << "\n\tError: failed to load graph!\n";
        std::cin.get();
        return;
    }
    g.printMatrix();
    std::cout << ("\n\tEnter the starting city (1-" + std::to_string(g.getVertexCount()) + "): ");
    int K = Input_Int();
    std::cout << ("\n\tEnter the number of transfers: ");
    int L = Input_Int();
    g.printResult(K, L);
    std::cout << "  /\\_/\\\n" << " ( V.V )\n" << "  > ^ <\n";
}