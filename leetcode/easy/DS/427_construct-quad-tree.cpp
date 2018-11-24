#include "..\..\stdafx.h"
using namespace std;
NS(427)
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

//class Solution {
//public:
//    vector<vector<int>> sums;
//    void init(vector<vector<int>>& grid)
//    {
//        int N = grid.size();
//        sums = grid;
//        for (int i = 1; i < N; i++)
//            sums[0][i] += sums[0][i - 1];
//        for (int i = 1; i < N; i++)
//            sums[i][0] += sums[i - 1][0];
//        for (int i = 1; i < N; i ++)
//            for (int j = 1; j < N; j++)
//            {
//                sums[i][j] += sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
//            }
//    }
//    Node* construct(vector<vector<int>>& grid) {
//        init(grid);
//        int N = grid.size();
//        return construct(grid, 0, 0, N);
//    }
//    Node* construct(vector<vector<int>>& grid, int x, int y, int len)
//    {
//        if (len == 1) return new Node(grid[y][x] == 1, true, nullptr, nullptr, nullptr, nullptr);
//        int sum = sums[y + len - 1][x + len - 1];
//        if (y >= 1) sum -= sums[y - 1][x + len - 1];
//        if (x >= 1) sum -= sums[y + len - 1][x - 1];
//        if (y >= 1 && x >= 1) sum += sums[y - 1][x - 1];
//        if (sum == 0) return new Node(false, true, nullptr, nullptr, nullptr, nullptr);
//        if (sum == len * len) return new Node(true, true, nullptr, nullptr, nullptr, nullptr);
//        int half = len >> 1;
//        return new Node(true, false,
//            construct(grid, x, y, half),
//            construct(grid, x + half, y, half),
//            construct(grid, x, y + half, half),
//            construct(grid, x + half, y + half, half));
//    }
//};
class Solution {
public:
    void init(vector<vector<int>>& grid)
    {
        int N = grid.size();
        for (int i = 1; i < N; i++)
            grid[0][i] += grid[0][i - 1];
        for (int i = 1; i < N; i++)
            grid[i][0] += grid[i - 1][0];
        for (int i = 1; i < N; i++)
            for (int j = 1; j < N; j++)
            {
                grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
            }
    }
    Node* construct(vector<vector<int>>& grid) {
        init(grid);
        int N = grid.size();
        return construct(grid, 0, 0, N);
    }
    Node* construct(vector<vector<int>>& grid, int x, int y, int len)
    {
        int sum = grid[y + len - 1][x + len - 1];
        if (y >= 1) sum -= grid[y - 1][x + len - 1];
        if (x >= 1) sum -= grid[y + len - 1][x - 1];
        if (y >= 1 && x >= 1) sum += grid[y - 1][x - 1];
        if (sum == 0) return new Node(false, true, nullptr, nullptr, nullptr, nullptr);
        if (sum == len * len) return new Node(true, true, nullptr, nullptr, nullptr, nullptr);
        int half = len >> 1;
        return new Node(true, false,
            construct(grid, x, y, half),
            construct(grid, x + half, y, half),
            construct(grid, x, y + half, half),
            construct(grid, x + half, y + half, half));
    }
};
END_NS