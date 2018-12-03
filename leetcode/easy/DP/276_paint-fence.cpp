#include "..\..\stdafx.h"
using namespace std;
NS(276)
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        if (n == 1) return k;
        if (n == 2) return k * k;
        int prev2 = k;
        int prev = k * k;
        int cur;
        // bn = (k-1)(b(n-1)+b(n-2))
        for (int i = 3; i <= n; i++)
        {
            cur = (k - 1) * (prev2 + prev);
            prev2 = prev;
            prev = cur;            
        }

        return cur;
    }
};
END_NS