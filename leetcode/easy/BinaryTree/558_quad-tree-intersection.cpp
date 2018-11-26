#include "..\..\stdafx.h"
using namespace std;
NS(558)

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1->isLeaf)
        {
            if (quadTree1->val) return quadTree1;
            else return quadTree2;
        }

        if (quadTree2->isLeaf)
        {
            if (quadTree2->val) return quadTree2;
            else return quadTree1;
        }

        Node* tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node* tr = intersect(quadTree1->topRight, quadTree2->topRight);
        Node* br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        Node* bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);

        if (tl->isLeaf && tr->isLeaf && br->isLeaf && bl->isLeaf && 
            (tl->val == tr->val && tl->val == br->val && tl->val == bl->val))
        {
            return new Node(tl->val, true, nullptr, nullptr, nullptr, nullptr);
        }

        quadTree1->topLeft = tl;
        quadTree1->topRight = tr;
        quadTree1->bottomLeft = bl;
        quadTree1->bottomRight = br;
        return quadTree1;
    }
};
END_NS