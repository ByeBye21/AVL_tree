/**
* @file AVLNode.h
* @description AVL Ağaçları ve Stack Listeler Kullanarak Tam Sayıları Depolama İşlemleri Yapılıyor
* @course 1.Öğretim B Grubu
* @assignment 2.Ödev
* @date 2023/12/24
* @author Younes Rahebi | younes0079@gmail.com
*/

#include "AVLNode.h"

AVLNode::AVLNode(const int& data, AVLNode* left, AVLNode* right) : data{ data }, left{ left }, right{ right }, height{ 0 } {}

AVLNode::~AVLNode() {}