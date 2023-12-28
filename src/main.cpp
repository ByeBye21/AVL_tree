/**
* @file main.cpp
* @description AVL Ağaçları ve Stack Listeler Kullanarak Tam Sayıları Depolama İşlemleri Yapılıyor
* @course 1.Öğretim B Grubu
* @assignment 2.Ödev
* @date 2023/12/24
* @author Younes Rahebi | younes0079@gmail.com
*/

#include "AVL.h"
#include "AVLDynamicArray.h"
#include "StackDynamicArray.h"
#include <iomanip>
#include <climits>

AVLDynamicArray readFromFile(const std::string& fileName) {

    std::ifstream inFile(fileName);

    std::string line;

    AVLDynamicArray avlTrees;

    int treeID = 1;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        int number;
        AVL* newTree = new AVL(treeID);

        while (iss >> number) {
            newTree->add(number);
        }

        avlTrees.addAVL(newTree);
        treeID++;
    }

    inFile.close();

    return avlTrees;
}

int main() {
    AVLDynamicArray avlTrees = readFromFile("Veri.txt");


    while (avlTrees.count > 1) {

        StackDynamicArray stackLeaves;

        for (int i = 0; i < avlTrees.count; ++i) {
            AVL* currentAVLTree = avlTrees.getAVL(i);
            if (currentAVLTree != nullptr) {
                Stack* leavesStack = new Stack;
                currentAVLTree->postorderWithStack(currentAVLTree->root, *leavesStack);
                stackLeaves.addStack(leavesStack);
            }
        }

        bool removeSmallest = true;

        while (stackLeaves.count > 1) {
            int targetIndex = -1;
	    int targetValue = removeSmallest ? INT_MAX : INT_MIN;

            for (int i = 0; i < stackLeaves.count; ++i) {
                if (stackLeaves.getStack(i)->empty()) {
                    continue;
                }

                int currentTop = stackLeaves.getStack(i)->top();
                bool isTarget = removeSmallest ? (currentTop < targetValue) : (currentTop > targetValue);

                if (isTarget) {
                    targetValue = currentTop;
                    targetIndex = i;
                }
            }

            if (targetIndex == -1) {
                break;
            }

            stackLeaves.getStack(targetIndex)->pop();
            removeSmallest = !removeSmallest;

            if (stackLeaves.getStack(targetIndex)->empty()) {
                avlTrees.removeAt(targetIndex);
                stackLeaves.removeAt(targetIndex);

                for (int i = 0; i < avlTrees.count; ++i) {
                    AVL* currentAVL = avlTrees.getAVL(i);
                    if (currentAVL != nullptr) {
                        int nonLeafTotalValue = currentAVL->calculateNonLeafTotalValue(currentAVL->root);
                        int asciiValue = nonLeafTotalValue % (90 - 65 + 1) + 65;
                        std::cout << static_cast<char>(asciiValue);
                    }
                }

                system("CLS");

                break;
            }
        }
    }

    AVL* avl = avlTrees.getAVL(0);

    std::cout << "\n#########################\n#";
    std::cout << std::setw(15) << "AVL No: " << std::setw(4) << avl->id << std::setw(7) << "#\n#";
    std::cout << std::setw(15) << "Son Karakter: " << std::setw(4) << static_cast<char>(avl->calculateNonLeafTotalValue(avl->root) % (90 - 65 + 1) + 65);
    std::cout << std::setw(5) << '#' << "\n#########################\n";

    return 0;
}