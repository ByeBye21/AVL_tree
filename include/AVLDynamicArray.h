/**
* @file AVLDynamicArray.h
* @description AVL Ağaçları ve Stack Listeler Kullanarak Tam Sayıları Depolama İşlemleri Yapılıyor
* @course 1.Öğretim B Grubu
* @assignment 2.Ödev
* @date 2023/12/24
* @author Younes Rahebi | younes0079@gmail.com
*/

#ifndef _AVLDYNAMICARRAY_H_
#define _AVLDYNAMICARRAY_H_
#include  "AVL.h"

struct AVLDynamicArray {

    AVL** array;
    int capacity;
    int count;

    AVLDynamicArray();

    ~AVLDynamicArray();

    void addAVL(AVL* avlTree);

    AVL* getAVL(int index) const;

    void removeAt(int index);
};

#endif