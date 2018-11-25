#include "..\..\stdafx.h"
using namespace std;
NS(938)
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
    class Solution {
    public:
        int rangeSumBST(TreeNode* root, int L, int R) {
            if (root == nullptr) return 0;
            if (L > R) return 0;
            if (root->val < L) return rangeSumBST(root->right, L, R);
            else if (root->val > R) return rangeSumBST(root->left, L, R);
            else
            {
                return root->val + rangeSumBST(root->left, L, root->val - 1) + 
                    rangeSumBST(root->right, root->val + 1, R);
            }
        }
};
END_NS
