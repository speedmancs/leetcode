#include "..\..\stdafx.h"
using namespace std;
NS(701)

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
// recursive way
class Solution2 {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
        {
            return new TreeNode(val);
        }

        if (root->val > val)
        {
            TreeNode * leftRoot = insertIntoBST(root->left, val);
            root->left = leftRoot;
        }
        else
        {
            TreeNode * rightRoot = insertIntoBST(root->right, val);
            root->right = rightRoot;
        }
        return root;
    }
};

// iterative way
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
        {
            return new TreeNode(val);
        }
        
        TreeNode * prev = nullptr;
        TreeNode * current = root;
        while (current != nullptr)
        {
            prev = current;
            if (val > current->val) current = current->right;
            else current = current->left;
        }
        
        if (val < prev->val) prev->left = new TreeNode(val);
        else prev->right = new TreeNode(val);
        return root;
    }
};

END_NS
