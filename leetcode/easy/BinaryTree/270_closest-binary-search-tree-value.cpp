#include "..\..\stdafx.h"
using namespace std;
NS(270)
struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

// recursive way
//class Solution {
//public:
//    // lower_bound, find smallest node >= target
//    TreeNode* lower_bound(TreeNode* root, double target)
//    {
//        if (root == nullptr) return nullptr;
//        if (root->val < target) return lower_bound(root->right, target);
//        auto node = lower_bound(root->left, target);
//        if (node == nullptr) return root;
//        return node;
//    }
//
//    // upper_bound, find largest node <= target
//    TreeNode* upper_bound(TreeNode* root, double target)
//    {
//        if (root == nullptr) return nullptr;
//        if (root->val > target) return upper_bound(root->left, target);
//        auto node = upper_bound(root->right, target);
//        if (node == nullptr) return root;
//        return node;
//    }
//
//    int closestValue(TreeNode* root, double target) {
//        TreeNode* node1 = lower_bound(root, target);
//        TreeNode* node2 = upper_bound(root, target);
//        if (node1 == nullptr) return node2->val;
//        if (node2 == nullptr) return node1->val;
//        if (node1->val - target < target - node2->val) return node1->val;
//        return node2->val;
//    }
//};

// non-recursive way
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        TreeNode* cur = root;
        int result;
        double minDis = numeric_limits<double>::max();
        while (cur)
        {
            double dis = abs(cur->val - target);
            if (dis < minDis)
            {
                minDis = dis;
                result = cur->val;
            }

            if (target > cur->val)
                cur = cur->right;
            else
                cur = cur->left;
        }
        return result;
    }
};
END_NS
