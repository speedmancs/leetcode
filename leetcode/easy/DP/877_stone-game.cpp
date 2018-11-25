#include "..\..\stdafx.h"
using namespace std;
NS(877)
//class Solution {
//public:
//    bool stoneGame(vector<int>& piles) {
//        int n = piles.size();
//        // dp[i][j]: the most diff when picking from piles[i:j]
//        vector<vector<int>> dp(n, vector<int>(n, 0));
//        for (int i = 0; i < n; i++)
//            dp[i][i] = piles[i];
//        for (int gap = 1; gap <= n - 1; gap++)
//        {
//            for (int i = 0; i + gap < n; i++)
//            {
//                int j = i + gap;
//                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
//            }
//        }
//        return dp[0][n - 1] > 0;
//    }
//};

// preparation for space O(n)
//class Solution {
//public:
//    bool stoneGame(vector<int>& piles) {
//        int n = piles.size();
//        // dp[gap][i]: the most diff when picking from piles[i:(i + gap)]
//        vector<vector<int>> dp(n, vector<int>(n, 0));
//        for (int i = 0; i < n; i++)
//            dp[0][i] = piles[i];
//        for (int gap = 1; gap <= n - 1; gap++)
//        {
//            for (int i = 0; i + gap < n; i++)
//            {
//                int j = i + gap;
//                dp[gap][i] = max(piles[i] - dp[gap - 1][i+1], piles[j] - dp[gap - 1][i]);
//            }
//        }
//        return dp[n - 1][0] > 0;
//    }
//};

// space O(n)
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        // dp[i]: the most diff when picking from piles[i:(i + gap)]
        vector<int> dp(n, 0);
        int gap = 0;
        for (int i = 0; i < n; i++)
            dp[i] = piles[i];
        for (int gap = 1; gap <= n - 1; gap++)
        {
            for (int i = 0; i + gap < n; i++)
            {
                int j = i + gap;
                dp[i] = max(piles[i] - dp[i + 1], piles[j] - dp[i]);
            }
        }
        return dp[0] > 0;
    }
};
END_NS