#include "..\..\stdafx.h"
using namespace std;
NS(589)

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> output;
    vector<int> preorder(Node* root) {
        if (root == nullptr) return output;
        _preorder(root);
        return output;
    }
    void _preorder(Node* root)
    {
        output.push_back(root->val);
        for (auto node : root->children)
            _preorder(node);
    }
};
END_NS
