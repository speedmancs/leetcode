#include "..\..\stdafx.h"
using namespace std;
NS(874)
struct pair_hash {
    inline std::size_t operator()(const std::pair<int, int> & v) const {
        return v.first * 31 + v.second;
    }
};

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<pair<int, int>, pair_hash> obSet;
        for (auto& v : obstacles) obSet.insert(make_pair(v[0], v[1]));
        int maxDis = 0;
        // north, west, south, east
        int dx[] = {0, -1, 0, 1};
        int dy[] = { 1, 0, -1, 0 };
        int dir = 0;
        int cx = 0;
        int cy = 0;
        for (auto c : commands)
        {
            if (c == -2 || c == -1)
            {
                dir = (c == -2) ? (dir + 1) % 4 : (dir + 3) % 4;
                continue;
            }
            int k;
            for (k = 1; k <= c; k++)
                if (obSet.find(make_pair(cx + dx[dir] * k, cy + dy[dir] * k)) != obSet.end()) break;
            cx += dx[dir] * (k - 1);
            cy += dy[dir] * (k - 1);
            maxDis = max(maxDis, cx * cx + cy * cy);
        }
        return maxDis;
    }
};
END_NS
