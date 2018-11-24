#include "..\..\stdafx.h"
using namespace std;
NS(429)
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            vector<int> layer;
            while (n--)
            {
                layer.push_back(q.front()->val);
                for (auto node : q.front()->children)
                {
                    q.push(node);
                }
                q.pop();
            }
            result.push_back(layer);
        }

        return result;
    }
};
END_NS