#include "..\..\stdafx.h"
using namespace std;
NS(897)
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root, TreeNode* tail)
    {
        if (root == nullptr) return tail;
        TreeNode* head = increasingBST(root->left, root);
        root->left = nullptr;
        root->right = increasingBST(root->right, tail);
        return head;
    }
    TreeNode* increasingBST(TreeNode* root) {
        return increasingBST(root, nullptr);
    }
};
END_NS
