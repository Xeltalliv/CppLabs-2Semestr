#pragma once
struct TNode {
    double value;
    TNode* left;
    TNode* right;

    void insertToTree(TNode*);
    double findMax();
};