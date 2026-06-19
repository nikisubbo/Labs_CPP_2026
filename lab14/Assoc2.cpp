#include "Assoc2.h"
#include "stl_utils.h"
#include <vector>
#include <set>
#include <algorithm>  
#include <iostream>

void Assoc2() {
    std::vector<int> V0 = get_vector_min_size("Enter vector V0 size: ", 1);
    std::cout << "\nVector V0: ";
    print_vector("V0", V0);
    int N = get_positive_number("Enter the number of vectors: ");
    std::set<int> set_V0(V0.begin(), V0.end());
    std::cout << "\nSet based on V0: ";
    for (int x : set_V0) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    int count = 0;
    std::vector<std::vector<int>> all_vectors;
    for (int i = 1; i <= N; ++i) {
        std::vector<int> Vi = get_vector_min_size("Enter vector V size" + std::to_string(i) + ": ", 1);
        all_vectors.push_back(Vi);
        std::set<int> set_Vi(Vi.begin(), Vi.end());
        if (std::includes(set_Vi.begin(), set_Vi.end(), set_V0.begin(), set_V0.end())) {
            std::cout << "Vector V" << i << " contains all elements of V0\n";
            count++;
        }
        else {
            std::cout << "Vector V" << i << " not contains all elements of V0\n";
        }
    }
    std::cout << "The number of vectors Vi containing all elements of V0: " << count << "\n";
    std::cout << "\nVectors:\n";
    for (int i = 0; i < N; ++i) {
        print_vector("V" + std::to_string(i + 1), all_vectors[i]);
    }
}