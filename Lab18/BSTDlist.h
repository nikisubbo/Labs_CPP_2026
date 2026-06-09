#pragma once
#include <vector>
class Node {
private:
    int key;//знач
    Node* left;//лев (prev)
    Node* right;//прав (next)
public:
    Node(int k);//констр
    int get_key() const;//геттер ключа
    Node* get_left() const;//геттер лев
    Node* get_right() const;//геттер прав
    void set_left(Node* node);//сеттер лев
    void set_right(Node* node);//сеттер прав
};
class BinaryTree {
private:
    Node* root;//корень
    void add(Node* node, int val);//добавл узла
    void print(Node* node, int level) const;//вывод дерева боком
    void convert(Node* node, Node*& head, Node*& prev);//лпк перепор
    void clear(Node* node);//рекурс удаление
public:
    BinaryTree();//констр
    ~BinaryTree();//дестр
    void CompletionTree(const std::vector<int>& data);//постр дерева из вектора
    void show() const;//вывод дерева
    Node* convert_to_list();//вернет голову
    void show_list(Node* head) const;//вывод списка
    void cleanup();//очистка
};
void HowToFill(BinaryTree& tree);
