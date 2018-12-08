#include "..\..\stdafx.h"
using namespace std;
NS(885)
//class Solution {
//public:
//    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
//        vector<vector<int>> results;
//        int step = 1;
//        int dx[] = { 1, 0, -1, 0 };
//        int dy[] = { 0, 1, 0, -1 };
//        int dir = 0;
//        vector<int> point(2);
//        point[0] = r0; point[1] = c0;
//        results.push_back(point);
//        int total = R * C;
//        int cx = c0;
//        int cy = r0;
//        while (results.size() != total)
//        {
//            for (int k = 0; k < 2; k++)
//            {
//                for (int i = 0; i < step; i++)
//                {
//                    cx += dx[dir];
//                    cy += dy[dir];
//                    Update(cx, cy, R, C, results);
//                }
//                dir = (dir + 1) % 4;
//            }
//            step++;
//        }
//        return results;
//    }
//
//    void Update(int x, int y, int R, int C, vector<vector<int>>& results)
//    {
//        if (x >= 0 && x < C && y >= 0 && y < R)
//        {
//            vector<int> point(2);
//            point[0] = y; point[1] = x;
//            results.push_back(point);
//        }
//    }
//};

// optimization
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> results;
        int step = 1;
        int dx[] = { 1, 0, -1, 0 };
        int dy[] = { 0, 1, 0, -1 };
        int dir = 0;
        vector<int> point(2);
        point[0] = r0; point[1] = c0;
        results.push_back(point);
        int total = R * C;
        int cx = c0;
        int cy = r0;
        while (results.size() != total)
        {
            for (int k = 0; k < 2; k++)
            {
                int oriX = cx;
                int oriY = cy;
                if (((dir == 0 || dir == 2) && (cy >= R || cy < 0)) ||
                    (dir == 1 || dir == 3) && (cx >= C || cx < 0))
                {
                    cx = oriX + step * dx[dir];
                    cy = oriY + step * dy[dir];
                    dir = (dir + 1) & 0x3;
                    continue;
                }

                for (int i = 0; i < step; i++)
                {
                    if ((dir == 0 && (cx >= C - 1)) ||
                        (dir == 1 && (cy >= R - 1)) ||
                        (dir == 2 && cx <= 0) ||
                        (dir == 3 && cy <= 0))
                    {
                        cx = oriX + step * dx[dir];
                        cy = oriY + step * dy[dir];
                        break;
                    }

                    cx += dx[dir];
                    cy += dy[dir];
                    if (cx >= 0 && cx < C && cy >= 0 && cy < R)
                    {
                        point[0] = cy; point[1] = cx;
                        results.push_back(point);
                    }
                }
                dir = (dir + 1) & 0x3;
            }
            step++;
        }
        return results;
    }
};

void Test()
{
    Solution().spiralMatrixIII(1, 4, 0, 0);
}
END_NS
