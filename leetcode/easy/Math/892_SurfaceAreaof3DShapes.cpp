#include "..\..\stdafx.h"
using namespace std;
NS(892)
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int N = grid.size();
        int cubes = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cubes += grid[i][j];
        int totalArea = 6 * cubes;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] > 1)
                    totalArea -= (grid[i][j] - 1) << 1;
            }
        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < N - 1; c++)
                totalArea -= min(grid[r][c], grid[r][c + 1]) << 1;
        }

        for (int c = 0; c < N; c++)
        {
            for (int r = 0; r < N - 1; r++)
                totalArea -= min(grid[r][c], grid[r + 1][c]) << 1;
        }
        return totalArea;
    }
};
END_NS