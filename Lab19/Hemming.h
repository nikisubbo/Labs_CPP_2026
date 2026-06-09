#pragma once
#include <vector>
#include <string>
class HemmingCode {
private:
    std::vector<int> data;//исходное сообщение
    std::vector<int> code;//кодовое слово
    int r, m, n, errPos;//контр биты, информ биты, длина, ошибка
    void calcControlBits();//расч контро битов
    int syndrome() const;//вычисление синдрома
public:
    explicit HemmingCode(const std::string& bits);//констр
    void insertError(int pos);//внести ошибку
    void run();//запуск (кодирование +синдром)
    void printEmpty() const;//таблица до 
    void printFull() const;//таблица после 
    int get_n() const { return n; }//геттер длины
    void printSyndrome() const;//вывод синдромов
};
void HowToFillHemming(std::string& msg);