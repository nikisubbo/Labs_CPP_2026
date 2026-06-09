#pragma once
#include <vector>
#include <stack>
#include <queue>
class Node3 {
private:
    int key;//знач
    Node3* left;//лев
    Node3* right;//прав
public:
    Node3(int k);//констр
    int get_key() const;//геттер
    Node3* get_left() const;
    Node3* get_right() const;
    void set_left(Node3* node);
    void set_right(Node3* node);
};
class TreeIterator {//итератор симетрич обхода
private:
    std::stack<Node3*> st;//стек для узелков
    Node3* curr;//текущий узел
public:
    TreeIterator(Node3* root);//констр
    bool has_next();//есть ли следующий
    int next();//следующий элемент
};
class BTree {
private:
    Node3* root;//корень
    void print_node(Node3* node, int level) const;//вывод
    void clear_node(Node3* node);//очистка
public:
    BTree();//констр
    ~BTree();//дестр
    void build(const std::vector<int>& data);//постр
    void print() const;//вывод
    void cleanup();//очистка
    TreeIterator get_iter() const;//получить итератор
};
void HowToFill(BTree& tree);