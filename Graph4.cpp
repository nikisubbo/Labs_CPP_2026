#include "Graph4.h"
#include "sup.h"
#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <limits>
Graph4::Graph4() : n(0) {}
Graph4::Graph4(const std::string& filename) : n(0) {
    loadFromFile(filename);
}
Graph4::Graph4(int size) : n(size) {
    adj.assign(n, std::vector<int>(n, 0));
}
Graph4::Graph4(const std::vector<std::vector<int>>& matrix) {
    adj = matrix;
    n = (int)adj.size();
    if (!validateMatrix()) {
        n = 0;
        adj.clear();
    }
}
bool Graph4::validateMatrix() const {
    if (n <= 0) {
        std::cout << "\nError: n <= 0\n";
        return false;
    }
    for (const auto& row : adj)
        if ((int)row.size() != n) {
            std::cout << "\nError: matrix is not square\n";
            return false;
        }
    return true;
}
void Graph4::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) {
        std::cout << "\nError: cannot create file " << filename << "\n";
        return;
    }
    out << n << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) out << adj[i][j] << " ";
        out << "\n";
    }
    out.close();
    std::cout << "\nMatrix saved to " << filename << "\n";
}
void Graph4::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cout << "\nError: file \"" << filename << "\" not found!\n";
        n = 0;
        return;
    }
    if (!(in >> n) || n <= 0) {
        std::cout << "\nError: invalid number of vertices\n";
        n = 0;
        return;
    }
    adj.assign(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (!(in >> adj[i][j])) {
                std::cout << "\nError: failed to read matrix\n";
                n = 0;
                return;
            }
    in.close();
    if (!validateMatrix()) {
        n = 0;
        adj.clear();
    }
}
std::vector<int> Graph4::bfs(int start) const {
    if (n == 0 || start < 0 || start >= n) return {};
    std::vector<bool> visited(n, false);
    std::vector<int> order;
    std::queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        order.push_back(v);
        std::vector<int> neighbors;
        for (int to = 0; to < n; ++to)
            if (adj[v][to] != 0 && !visited[to])
                neighbors.push_back(to);
        std::sort(neighbors.begin(), neighbors.end());
        for (int to : neighbors) {
            visited[to] = true;
            q.push(to);
        }
    }
    return order;
}
void Graph4::printBFS(int start) const {
    if (n == 0) {
        std::cout << "\nGraph not loaded\n";
        return;
    }
    if (start < 1 || start > n) {
        std::cout << "\nError: vertex must be from 1 to " << n << "\n";
        return;
    }
    int startZero = start - 1;
    std::vector<int> order = bfs(startZero);
    std::cout << "\nBFS from vertex " << start << ":\n\t";
    for (int v : order) std::cout << v + 1 << " ";
    std::cout << "\n";
}
void Graph4::printMatrix() const {
    std::cout << "\nAdjacency matrix (" << n << " vertices):\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "\t";
        for (int j = 0; j < n; ++j) std::cout << adj[i][j] << " ";
        std::cout << "\n";
    }
}
Graph4 Graph4::fromKeyboard() {
    std::cout << "Enter number of vertices: ";
    int n = Input_Int();
    std::vector<std::vector<int>> mat(n, std::vector<int>(n));
    std::cout << "\nEnter adjacency matrix (weights, 0 if no edge):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] = Input_Int();
        }
    }
    Graph4 g(mat);
    g.saveToFile("FileName");
    return g;
}
Graph4 Graph4::fromRandom() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);
    std::uniform_int_distribution<> wdis(1, 10);
    int n;
    std::cout << "\nEnter number of vertices: ";
    std::cin >> n;
    std::vector<std::vector<int>> mat(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j && dis(gen) == 1)
                mat[i][j] = wdis(gen);
    Graph4 g(mat);
    g.saveToFile("Graph4.txt");
    return g;
}
Graph4 Graph4::fromFile() {
    std::string filename;
    std::cout << "\nEnter filename: ";
    std::cin >> filename;
    return Graph4(filename);
}