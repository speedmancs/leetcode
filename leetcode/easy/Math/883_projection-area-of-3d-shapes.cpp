#include "..\..\stdafx.h"
using namespace std;
NS(883)
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int area = 0;
        int Row = grid.size();
        if (Row == 0) return 0;
        int Col = grid[0].size();
        for (auto& v : grid)
            for (auto h : v)
            {
                if (h != 0) area++;
            }
        for (auto& v : grid)
        {
            int maxHeight = *std::max_element(v.begin(), v.end());
            if (maxHeight != 0) area += maxHeight;
        }

        for (int i = 0; i < Col; i++)
        {
            int maxHeight = INT_MIN;
            for (int j = 0; j < Row; j++)
                maxHeight = max(maxHeight, grid[j][i]);
            if (maxHeight != 0) area += maxHeight;
        }
        return area;
    }
};
END_NS