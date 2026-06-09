#pragma once
#include <string>
#include <vector>
#include <map>
#include <queue>
class HaffmanNode {
private:
    char sym;//символ
    int freq;//частота
    HaffmanNode* left;//левый
    HaffmanNode* right;//правый
public:
    HaffmanNode(char sym, int freq);//констр
    char get_sym() const;//геттер символа
    int get_freq() const;//геттер частоты
    HaffmanNode* get_left() const;
    HaffmanNode* get_right() const;
    void set_left(HaffmanNode* node);
    void set_right(HaffmanNode* node);
};
class NodeComparator {//компаратор для мин-кучи
public:
    bool operator()(HaffmanNode* a, HaffmanNode* b) const;
};
class HaffmanCoder {
private:
    std::string text;//исходный текст
    std::map<char, int> freqs;//таблица частот
    std::map<char, std::string> codes;//таблица кодов
    HaffmanNode* root;//корень дерева
    int totalBits;//общее кол-во бит по Хаффману
    std::string encodedBits;//закодированная битовая строка
    void buildTree();//построение дерева
    void generateCodes(HaffmanNode* node, std::string code);//генерация кодов
    void deleteTree(HaffmanNode* node);//очистка памяти
    void printTreeRecursive(HaffmanNode* node, int level) const;//вывод дерева
public:
    HaffmanCoder(const std::string& txt);//констр
    ~HaffmanCoder();//дестр
    void encode();//запуск кодирования
    std::string decode(const std::string& bits, HaffmanNode* treeRoot);//раскодирование
    std::string getEncodedBits() const { return encodedBits; }//геттер битовой строки
    std::string decodeFromTree(const std::string& bits) const;//раскодирование по готовому дереву
    void printTree() const;//вывод дерева
    void printTable() const;//вывод таблицы
    void printStats() const;//вывод статистики
    void printEncodedBits() const;//вывод битовой строки
    void printDecoded(const std::string& bits, HaffmanNode* tree);//вывод раскодированного
};
void HowToFillHaffman(std::string& msg);