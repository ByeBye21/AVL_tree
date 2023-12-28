/**
* @file AVLDynamicArray.h
* @description AVL Ağaçları ve Stack Listeler Kullanarak Tam Sayıları Depolama İşlemleri Yapılıyor
* @course 1.Öğretim B Grubu
* @assignment 2.Ödev
* @date 2023/12/24
* @author Younes Rahebi | younes0079@gmail.com
*/

#include "AVLDynamicArray.h"

AVLDynamicArray::AVLDynamicArray() : array(nullptr), capacity(0), count(0) {}

AVLDynamicArray::~AVLDynamicArray() {
    for (int i = 0; i < count; ++i) {
        delete array[i];
        array[i] = nullptr;
    }
    delete[] array;
}

void AVLDynamicArray::addAVL(AVL* avlTree) {
    if (count == capacity) {
        int newCapacity = capacity == 0 ? 4 : capacity * 2;
        AVL** newArray = new AVL * [newCapacity];
        for (int i = 0; i < count; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }
    array[count++] = avlTree;
}

AVL* AVLDynamicArray::getAVL(int index) const {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Index is out of bounds");
    }
    return array[index];
}

void AVLDynamicArray::removeAt(int index) {
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