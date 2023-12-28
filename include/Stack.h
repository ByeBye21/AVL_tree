/**
* @file Stack.h
* @description AVL Ağaçları ve Stack Listeler Kullanarak Tam Sayıları Depolama İşlemleri Yapılıyor
* @course 1.Öğretim B Grubu
* @assignment 2.Ödev
* @date 2023/12/24
* @author Younes Rahebi | younes0079@gmail.com
*/

#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>

class Stack {

private:

    friend std::ostream& operator<<(std::ostream& os, const Stack& stack);
    int peek;
    int capacity;
    int* data;
    void expand(int size);

public:

    Stack();
    ~Stack();
    int top() const;
    void pop();
    void push(int data);
    bool empty() const;
};

#endif