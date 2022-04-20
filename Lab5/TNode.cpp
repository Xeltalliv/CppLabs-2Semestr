#include "TNode.h"

void TNode::insertToTree(TNode* insert) {
    if (insert->value > value) {
        if (right == nullptr) {
            right = insert;
        } else {
            right->insertToTree(insert);
        }
    } else if (insert->value < value) {
        if (left == nullptr) {
            left = insert;
        } else {
            left->insertToTree(insert);
        }
    }
}

double TNode::findMax() {
    if (right == nullptr) {
        return value;
    } else {
        return right->findMax();
    }
}