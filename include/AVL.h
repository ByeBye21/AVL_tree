/**
* @file AVL.h
* @description AVL Ağaçları ve Stack Listeler Kullanarak Tam Sayıları Depolama İşlemleri Yapılıyor
* @course 1.Öğretim B Grubu
* @assignment 2.Ödev
* @date 2023/12/24
* @author Younes Rahebi | younes0079@gmail.com
*/

#ifndef _AVL_H_
#define _AVL_H_

#include "AVLNode.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <sstream>

class AVL {

private:

    AVLNode* swapWithLeftChild(AVLNode* subNode);
    AVLNode* swapWithRightChild(AVLNode* subNode);
    bool search(AVLNode* subNode, const int& data);
    AVLNode* searchAndAdd(AVLNode* subNode, const int& data);
    AVLNode* searchAndDelete(AVLNode* subNode, const int& data);
    bool deleteNode(AVLNode*& subNode);
    int height(AVLNode* subNode) const;
    bool isLeaf(AVLNode* node) const;
    int calculateTotalValue(AVLNode* subNode);

public:

    AVLNode* root;
    int id;
    AVL(int treeID);
    ~AVL();
    bool isEmpty() const;
    void add(const int& data);
    void remove(const int& data);
    int height();
    bool search(const int& data);
    void postorderWithStack(AVLNode* subNode, Stack& stack) const;
    int calculateNonLeafTotalValue(AVLNode* subNode) const;

};

#endif