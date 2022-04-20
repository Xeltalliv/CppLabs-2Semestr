#include <iostream>
#include <Windows.h>
#include "TNode.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "ЛАБОРАТОРНА РОБОТА 5\n\n";
    std::cout << "Бінарні дерева\n";

    TNode* rootNode = nullptr;
    int nodeCount;
    std::cout << "Кількість елементів в дереві: ";
    std::cin >> nodeCount;
    for (int i = 0; i < nodeCount; i++) {
        TNode* node = new TNode();
        std::cout << " Елемент " << i+1 << ": ";
        std::cin >> node->value;
        node->left = node->right = nullptr;
        if (rootNode == nullptr) {
            rootNode = node;
        } else {
            rootNode->insertToTree(node);
        }
    }

    if(rootNode != nullptr) std::cout << "\nМаксимальне значення: " << rootNode->findMax();
}