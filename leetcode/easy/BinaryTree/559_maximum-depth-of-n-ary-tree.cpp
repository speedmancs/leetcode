#include "..\..\stdafx.h"
using namespace std;
NS(429)

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

//// recursive
//class Solution {
//public:
//    int maxDepth(Node* root) {
//        if (root == nullptr) return 0;
//        if (root->children.empty()) return 1;
//        int depth = INT_MIN;
//        for (auto node : root->children)
//        {
//            depth = max(depth, maxDepth(node) + 1);
//        }
//        return depth;
//    }
//};

// non-recursive: BSF
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        if (root->children.empty()) return 1;

        queue<Node*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty())
        {
            depth++;
            int n = q.size();
            while (n--)
            {
                for (auto node : q.front()->children)
                    q.push(node);
                q.pop();
            }
        }
        return depth;

    }
};
END_NS