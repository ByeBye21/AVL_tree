/**
* @file Stack.cpp
* @description AVL Ağaçları ve Stack Listeler Kullanarak Tam Sayıları Depolama İşlemleri Yapılıyor
* @course 1.Öğretim B Grubu
* @assignment 2.Ödev
* @date 2023/12/24
* @author Younes Rahebi | younes0079@gmail.com
*/

#include "Stack.h"

Stack::Stack() : peek(-1), capacity(5), data(new int[capacity]) {}

Stack::~Stack() {
    delete[] data;
}

void Stack::expand(int size) {
    int* newData = new int[size + capacity];
    for (int i{}; i <= peek; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity += size;
}

int Stack::top() const {
    return (peek != -1) ? data[peek] : NULL;
}

void Stack::pop() {
    if (peek != -1) {
        --peek;
    }
}

void Stack::push(int data) {
    if (peek == capacity - 1)
        expand(capacity);
    ++peek;
    this->data[peek] = data;
}

bool Stack::empty() const {
    return peek == -1;
}

std::ostream& operator<<(std::ostream& os, const Stack& stack) {
    for (int i{}; i <= stack.peek; i++) {
        os << stack.data[i] << " ";
    }
    os << std::endl;
    return os;
}