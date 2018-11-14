#include "..\..\stdafx.h"
using namespace std;
NS(366)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> findLeaves(TreeNode* root) {
        DFS(root);
        return result;
    }

    int DFS(TreeNode* root)
    {
        if (root == nullptr){
            return -1;
        }
        int leftLevel = DFS(root->left);
        int rightLevel = DFS(root->right);
        int level = max(leftLevel, rightLevel) + 1;
        if (level >= result.size()) result.push_back(vector<int>());
        result[level].push_back(root->val);
        return level;
    }
};

void Test()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution().findLeaves(root);
}
END_NS