#include "..\..\stdafx.h"
using namespace std;
NS(894)
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
//    class Solution {
//    public:
//        vector<TreeNode*> allPossibleFBT(int N) {
//            vector<TreeNode*> result;
//            if (N % 2 == 0) return result;
//            if (N == 1)
//            {
//                result.push_back(new TreeNode(0));
//                return result;
//            }
//
//            for (int k = 1; k <= N - 2; k += 2)
//            {
//                vector<TreeNode*> trees1 = allPossibleFBT(k);
//                vector<TreeNode*> trees2 = allPossibleFBT(N - 1 - k);
//                for (auto r1 : trees1)
//                {
//                    for (auto r2 : trees2)
//                    {
//                        TreeNode* root = new TreeNode(0);
//                        root->left = r1;
//                        root->right = r2;
//                        result.push_back(root);
//                    }
//                }
//            }
//            return result;
//        }
//};

// memorization
class Solution {
public:
    vector<vector<TreeNode*>> results;
    vector<TreeNode*> allPossibleFBT(int N)
    {
        vector<TreeNode*> result;
        if (N % 2 == 0) return result;
        results.resize(N + 1);
        _allPossibleFBT(N);
        return results[N];
    }

    void _allPossibleFBT(int N) {
        if (N == 1)
        {
            results[1].push_back(new TreeNode(0));
            return;
        }

        for (int k = 1; k <= N - 2; k += 2)
        {
            if (results[k].size() == 0)
            {
                _allPossibleFBT(k);
            }
            if (results[N - 1 - k].size() == 0)
            {
                _allPossibleFBT(N - 1 - k);
            }

            for (int i = 0; i < results[k].size(); i ++)
                for (int j = 0; j < results[N - 1 - k].size(); j++)
                {
                    TreeNode* root = new TreeNode(0);
                    root->left = results[k][i];
                    root->right = results[N - 1 - k][j];
                    results[N].push_back(root);
                }
        }
    }
};
END_NS
