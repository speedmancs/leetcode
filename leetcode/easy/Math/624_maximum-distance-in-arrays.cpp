#include "..\..\stdafx.h"
using namespace std;
NS(624)
//class Solution {
//public:
//    int maxDistance(vector<vector<int>>& arrays) {
//        pair<int, int> minValue = make_pair(INT_MAX, 0);
//        pair<int, int> maxValue = make_pair(INT_MIN, 0);
//        int index = 0;
//        for (auto& v : arrays)
//        {
//            if (v.front() < minValue.first)
//            {
//                minValue.first = v.front();
//                minValue.second = index;
//            }
//            if (v.back() > maxValue.first)
//            {
//                maxValue.first = v.back();
//                maxValue.second = index;
//            }
//            index++;
//        }
//
//        if (maxValue.second != minValue.second) return maxValue.first - minValue.first;
//        index = 0;
//        int result = INT_MIN;
//        for (auto& v : arrays)
//        {
//            if (index == minValue.second)
//            {
//                index++;
//                continue;
//            }
//            result = max(result, v.back() - minValue.first);
//            result = max(result, maxValue.first - v.front());
//            index++;
//        }
//        return result;
//    }
//};

// more simple
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0;
        int curMin = arrays[0].front();
        int curMax = arrays[0].back();
        for (int i = 1; i < arrays.size(); i++)
        {
            res = max(res, max(abs(curMin - arrays[i].back()), abs(curMax - arrays[i].front())));
            curMax = max(curMax, arrays[i].back());
            curMin = min(curMin, arrays[i].front());
        }
        return res;
    }
};
void Test()
{
    vector<vector<int>> v = { {1}, {1} };
    Solution().maxDistance(v);
}
END_NS
