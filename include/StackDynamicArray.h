/**
* @file StackDynamicArray.h
* @description AVL Ağaçları ve Stack Listeler Kullanarak Tam Sayıları Depolama İşlemleri Yapılıyor
* @course 1.Öğretim B Grubu
* @assignment 2.Ödev
* @date 2023/12/24
* @author Younes Rahebi | younes0079@gmail.com
*/

#ifndef _STACKDYNAMICARRAY_H_
#define _STACKDYNAMICARRAY_H_
#include "Stack.h"

struct StackDynamicArray {

    Stack** array;
    int capacity;
    int count;

    StackDynamicArray();

    ~StackDynamicArray();

    void addStack(Stack* stack);

    Stack* getStack(int index) const;

    void removeAt(int index);

    bool isEmpty() const;
};

#endif