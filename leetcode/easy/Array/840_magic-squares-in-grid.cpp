#include "..\..\stdafx.h"
using namespace std;
NS(840)
class Solution {
public:
    vector<vector<int>> sums;
    void Init(vector<vector<int>>& grid)
    {
        sums = grid;
        int Rows = grid.size();
        int Cols = grid[0].size();
        for (int c = 1; c < Cols; c++) sums[0][c] += sums[0][c - 1];
        for (int r = 1; r < Rows; r++) sums[r][0] += sums[r - 1][0];
        for (int r = 1; r < Rows; r ++)
            for (int c = 1; c < Cols; c++)
            {
                sums[r][c] += sums[r - 1][c] + sums[r][c - 1] - sums[r - 1][c - 1];
            }
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int Rows = grid.size();
        if (Rows < 3) return 0;
        int Cols = grid[0].size();
        if (Cols < 3) return 0;
        Init(grid);
        int count = 0;
        vector<int> digitCount = vector<int>(9, 0);

        for (int r = 0; r + 3 <= Rows; r++)
        {
            for (int c = 0; c + 3 <= Cols; c++)
            {
                // the sum of the region grid[r:r+3][c: c+3]
                // sum[r:r+3, c: c+3] = 
                // sum[r+2][c+2] - sum[r - 1][c + 2] - sum[r + 2][c - 1] + sum[r - 1][c - 1]
                int sum = getSum(r, c, 3, 3);
                if (sum != 45) continue;
                if (getSum(r, c, 1, 3) != 15 || getSum(r + 1, c, 1, 3) != 15 ||
                    getSum(r + 2, c, 1, 3) != 15 || getSum(r, c, 3, 1) != 15 ||
                    getSum(r, c + 1, 3, 1) != 15 || getSum(r, c + 2, 3, 1) != 15)
                    continue;
                if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != 15)
                    continue;
                if (grid[r + 2][c] + grid[r + 1][c + 1] + grid[r][c + 2] != 15)
                    continue;
                InitDigitCount(grid, r, c, digitCount);
                if (Check(digitCount))
                    count++;
            }
        }
        
        return count;
    }
    void InitDigitCount(vector<vector<int>>& grid, int r, int c, vector<int>& digitCount)
    {
        for (int i = 0; i < 9; i++) digitCount[i] = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                if (grid[r + i][c + j] >= 1 && grid[r + i][c + j] <= 9)
                    digitCount[grid[r + i][c + j] - 1] ++;
            }

    }
    bool Check(vector<int>& digitCount)
    {
        for (int i = 0; i < 9; i++)
        {
            if (digitCount[i] != 1) return false;
        }
        return true;
    }
    int getSum(int y, int x, int cy, int cx)
    {
        int regionSum = sums[y + cy - 1][x + cx - 1];
        if (y >= 1) regionSum -= sums[y - 1][x + cx - 1];
        if (x >= 1) regionSum -= sums[y + cy - 1][x - 1];
        if (y >= 1 && x >= 1) regionSum += sums[y - 1][x - 1];
        return regionSum;
    }
};
END_NS