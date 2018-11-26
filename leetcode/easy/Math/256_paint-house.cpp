#include "..\..\stdafx.h"
using namespace std;
NS(256)
// space O(n)
//class Solution {
//public:
//    int minCost(vector<vector<int>>& costs) {
//        int n = costs.size();
//        if (n == 0) return 0;
//        // dp[i][j]: the minimum cost for house[i:n) and house i is painted with color j
//        vector<vector<int>> dp = costs;
//        for (int i = n - 2; i >= 0; i--)
//        {
//            for (int j = 0; j < 3; j++)
//            {
//                dp[i][j] = INT_MAX;
//                int followed = 0;
//                for (int k = 0; k < 3; k++)
//                {
//                    if (k != j)
//                    {
//                        dp[i][j] = min(dp[i + 1][k] + costs[i][j], dp[i][j]);
//                    }
//                }
//            }
//        }
//        return min(min(dp[0][0], dp[0][1]), dp[0][2]);
//    }
//};

// space O(1)
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) return 0;
        // dp[j]: the minimum cost for house[i:n) and current house i is painted with color j
        vector<int> prevDp;
        vector<int> dp = costs[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            prevDp = dp;
            for (int j = 0; j < 3; j++)
            {
                dp[j] = INT_MAX;
                for (int k = 0; k < 3; k++)
                {
                    if (k != j)
                    {
                        dp[j] = min(prevDp[k] + costs[i][j], dp[j]);
                    }
                }
            }
        }

        return *std::min_element(dp.begin(), dp.end());
    }
};

void Test()
{
    vector<int> v = { 7,6,2 };
    //Solution().minCost(v);
}
END_NS