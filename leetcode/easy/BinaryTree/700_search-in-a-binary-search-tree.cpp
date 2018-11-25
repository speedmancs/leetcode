#include "..\..\stdafx.h"
using namespace std;
NS(700)
  struct TreeNode {
         int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
//// recursive
//class Solution {
//public:
//    TreeNode* searchBST(TreeNode* root, int val) {
//        if (root == nullptr) return nullptr;
//        if (root->val == val) return root;
//        if (root->val > val) return searchBST(root->left, val);
//        return searchBST(root->right, val);
//    }
//};

// non-recursive
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* node = root;
        while (node != nullptr && node->val != val)
        {
            if (val < node->val) node = node->left;
            else node = node->right;
        }
        return node;
    }
};
END_NS
