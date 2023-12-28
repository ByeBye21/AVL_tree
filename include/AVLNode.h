/**
* @file AVLNode.h
* @description AVL Ağaçları ve Stack Listeler Kullanarak Tam Sayıları Depolama İşlemleri Yapılıyor
* @course 1.Öğretim B Grubu
* @assignment 2.Ödev
* @date 2023/12/24
* @author Younes Rahebi | younes0079@gmail.com
*/

#ifndef _AVLNODE_H_
#define _AVLNODE_H_

class AVLNode {

private:

    friend class AVL;
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

public:

    AVLNode(const int& data, AVLNode* left = nullptr, AVLNode* right = nullptr);
    ~AVLNode();
};

#endif