#include "..\..\stdafx.h"
using namespace std;
NS(908)
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        for (auto x : A)
        {
            minValue = min(minValue, x);
            maxValue = max(maxValue, x);
        }
        return max(maxValue - minValue - 2 * K, 0);
    }
};
END_NS
