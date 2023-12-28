/**
* @file StackDynamicArray.cpp
* @description AVL Ağaçları ve Stack Listeler Kullanarak Tam Sayıları Depolama İşlemleri Yapılıyor
* @course 1.Öğretim B Grubu
* @assignment 2.Ödev
* @date 2023/12/24
* @author Younes Rahebi | younes0079@gmail.com
*/

#include "StackDynamicArray.h"

StackDynamicArray::StackDynamicArray() : array(nullptr), capacity(0), count(0) {}

StackDynamicArray::~StackDynamicArray() {
    for (int i = 0; i < count; ++i) {
        delete array[i];
    }
    delete[] array;
}

void StackDynamicArray::addStack(Stack* stack) {
    if (count == capacity) {
        int newCapacity = capacity == 0 ? 4 : capacity * 2;
        Stack** newArray = new Stack * [newCapacity];
        for (int i = 0; i < count; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }
    array[count++] = stack;
}

Stack* StackDynamicArray::getStack(int index) const {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Index is out of bounds");
    }
    return array[index];
}

void StackDynamicArray::removeAt(int index) {
    if (index < 0 || index >= count) {
        return;
    }

    delete array[index];

    for (int i = index; i < count - 1; ++i) {
        array[i] = array[i + 1];
    }

    count--;

    array[count] = nullptr;
}

bool StackDynamicArray::isEmpty() const {
    return count == 0;
}