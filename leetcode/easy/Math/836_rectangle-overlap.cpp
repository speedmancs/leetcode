#include "..\..\stdafx.h"
using namespace std;
NS(836)
class Solution {
public:
    bool isIntervalOverlap(int a, int b, int c, int d)
    {
        // [a, b] vs [c, d]
        return !(c >= b || d <= a);
    }
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return isIntervalOverlap(rec1[0], rec1[2], rec2[0], rec2[2])
            && isIntervalOverlap(rec1[1], rec1[3], rec2[1], rec2[3]);
    }
};
END_NS
