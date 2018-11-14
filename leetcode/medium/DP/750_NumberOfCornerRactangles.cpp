#include "..\..\stdafx.h"
using namespace std;
NS(750)
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int ROW = grid.size();
        int COL = grid[0].size();
        int count = 0;
        vector<vector<int>> dp(COL, vector<int>(COL, 0));
        for (int r = 0; r < ROW; r ++)
        {
            for (int c1 = 0; c1 < COL - 1; c1++)
            {
                if (grid[r][c1] == 0) continue;
                for (int c2 = c1 + 1; c2 < COL; c2 ++)
                {
                    if (grid[r][c2] == 0) continue;
                    count += dp[c1][c2];
                    dp[c1][c2] ++;
                }
            }
        }
        return count;
    }
};
END_NS