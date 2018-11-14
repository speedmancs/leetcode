#include "..\..\stdafx.h"
using namespace std;
NS(872)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs;
        InOrder(root1, leafs);
        int count = 0;
        return InOrderMatch(root2, count, leafs) && count == leafs.size();
    }

    bool InOrderMatch(TreeNode* root, int& count, vector<int>& expected)
    {
        if (root == nullptr) return true;
        bool matched = InOrderMatch(root->left, count, expected);
        if (!matched) return false;
        if (root->left == nullptr && root->right == nullptr)
        {
            if(expected[count] != root->val)
            {
                return false;
            }
            count ++;
        }
        return InOrderMatch(root->right, count, expected);
    }
    
    void InOrder(TreeNode* root, vector<int>& leafs)
    {
        if (root == nullptr) return;
        InOrder(root->left, leafs);
        if (root->left == nullptr && root->right == nullptr) leafs.push_back(root->val);
        InOrder(root->right, leafs);
    }
};

void Test()
{
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);
    TreeNode * root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(2);
    root2->right->right->left = new TreeNode(9);
    root2->right->right->right = new TreeNode(8);
    // Solution().leafSimilar(root1, root2);
    vector<int> leafs;
    cout << Solution().leafSimilar(root1, root2);
}
END_NS