/**
* @file AVL.cpp
* @description AVL Ağaçları ve Stack Listeler Kullanarak Tam Sayıları Depolama İşlemleri Yapılıyor
* @course 1.Öğretim B Grubu
* @assignment 2.Ödev
* @date 2023/12/24
* @author Younes Rahebi | younes0079@gmail.com
*/

#include "AVL.h"

AVL::AVL(int treeID) : root(nullptr), id(treeID) {}

AVL::~AVL() {
    while (!isEmpty()) {
        deleteNode(root);
    }
}

bool AVL::isEmpty() const {
    return root == nullptr;
}

AVLNode* AVL::swapWithLeftChild(AVLNode* subNode) {
    AVLNode* temp = subNode->left;
    subNode->left = temp->right;
    temp->right = subNode;
    subNode->height = height(subNode);
    temp->height = 1 + std::max(height(temp->left), subNode->height);
    return temp;
}

AVLNode* AVL::swapWithRightChild(AVLNode* subNode) {
    AVLNode* temp = subNode->right;
    subNode->right = temp->left;
    temp->left = subNode;
    subNode->height = height(subNode);
    temp->height = 1 + std::max(height(temp->right), subNode->height);
    return temp;
}

bool AVL::search(AVLNode* subNode, const int& data) {
    if (subNode == nullptr) {
        return false;
    }

    if (subNode->data == data) {
        return true;
    }

    if (data < subNode->data) {
        return search(subNode->left, data);
    }
    else {
        return search(subNode->right, data);
    }
}

bool AVL::search(const int& data) {
    return search(root, data);
}

AVLNode* AVL::searchAndAdd(AVLNode* subNode, const int& data) {
    if (subNode == nullptr) {
        subNode = new AVLNode(data);
    }
    else if (data < subNode->data) {
        subNode->left = searchAndAdd(subNode->left, data);
        if (height(subNode->left) == height(subNode->right) + 2) {
            if (data < subNode->left->data) {
                subNode = swapWithLeftChild(subNode);
            }
            else {
                subNode->left = swapWithRightChild(subNode->left);
                subNode = swapWithLeftChild(subNode);
            }
        }
    }
    else if (data > subNode->data) {
        subNode->right = searchAndAdd(subNode->right, data);
        if (height(subNode->right) == height(subNode->left) + 2) {
            if (data > subNode->right->data) {
                subNode = swapWithRightChild(subNode);
            }
            else {
                subNode->right = swapWithLeftChild(subNode->right);
                subNode = swapWithRightChild(subNode);
            }
        }
    }
    subNode->height = height(subNode);
    return subNode;
}

void AVL::add(const int& data) {
    root = searchAndAdd(root, data);
}

AVLNode* AVL::searchAndDelete(AVLNode* subNode, const int& data) {
    if (subNode == nullptr) {
        return subNode;
    }

    if (data < subNode->data) {
        subNode->left = searchAndDelete(subNode->left, data);
    }
    else if (data > subNode->data) {
        subNode->right = searchAndDelete(subNode->right, data);
    }
    else {
        deleteNode(subNode);
    }

    if (subNode == nullptr) {
        return subNode;
    }

    subNode->height = 1 + std::max(height(subNode->left), height(subNode->right));
    int balance = height(subNode->left) - height(subNode->right);

    if (balance > 1 && height(subNode->left->left) >= height(subNode->left->right)) {
        return swapWithLeftChild(subNode);
    }

    if (balance > 1 && height(subNode->left->left) < height(subNode->left->right)) {
        subNode->left = swapWithRightChild(subNode->left);
        return swapWithLeftChild(subNode);
    }

    if (balance < -1 && height(subNode->right->right) >= height(subNode->right->left)) {
        return swapWithRightChild(subNode);
    }

    if (balance < -1 && height(subNode->right->right) < height(subNode->right->left)) {
        subNode->right = swapWithLeftChild(subNode->right);
        return swapWithRightChild(subNode);
    }

    return subNode;
}

bool AVL::deleteNode(AVLNode*& subNode) {
    AVLNode* deleteNode = subNode;

    if (subNode->right == nullptr) {
        subNode = subNode->left;
    }
    else if (subNode->left == nullptr) {
        subNode = subNode->right;
    }
    else {
        deleteNode = subNode->left;
        AVLNode* parentNode = subNode;

        while (deleteNode->right != nullptr) {
            parentNode = deleteNode;
            deleteNode = deleteNode->right;
        }

        subNode->data = deleteNode->data;

        if (parentNode == subNode) {
            subNode->left = deleteNode->left;
        }
        else {
            parentNode->right = deleteNode->left;
        }
    }

    delete deleteNode;
    return true;
}

void AVL::remove(const int& data) {
    if (!isEmpty()) {
        root = searchAndDelete(root, data);
    }
    else {
        std::cout << "Item not found";
    }
}

int AVL::height(AVLNode* subNode) const {
    if (subNode == nullptr) {
        return -1;
    } else {
        return 1 + std::max(height(subNode->left), height(subNode->right));
    }
}

int AVL::height() {
    return height(root);
}

bool AVL::isLeaf(AVLNode* node) const {
    return (node->left == nullptr && node->right == nullptr);
}

int AVL::calculateTotalValue(AVLNode* subNode) {
    return (subNode == nullptr) ? 0 : subNode->data + calculateTotalValue(subNode->left) + calculateTotalValue(subNode->right);
}

int AVL::calculateNonLeafTotalValue(AVLNode* subNode) const {
    if (subNode == nullptr) {
        return 0;
    }
    int totalValue = 0;
    if (!isLeaf(subNode)) {
        totalValue = subNode->data;
    }
    return totalValue + calculateNonLeafTotalValue(subNode->left) + calculateNonLeafTotalValue(subNode->right);
}

void AVL::postorderWithStack(AVLNode* subNode, Stack& stack) const {
    if (subNode != nullptr) {
        postorderWithStack(subNode->left, stack);
        postorderWithStack(subNode->right, stack);
        if (isLeaf(subNode)) {
            stack.push(subNode->data);
        }
    }
}