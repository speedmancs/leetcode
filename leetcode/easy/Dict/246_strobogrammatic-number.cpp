#include "..\..\stdafx.h"
using namespace std;
NS(246)
class Solution {
public:
    bool isStrobogrammatic(string num) {
        int dict[10] = { 0, 1, -1, -1, -1, -1, 9, -1, 8, 6 };
        for (auto x : num)
        {
            if (dict[x - '0'] == -1) return false;
        }
        if (num.back() == '0') return false;
        int n = num.size();
        int i = 0;
        int j = n - 1;
        while (i < j)
        {
            if (dict[num[i] - '0'] != num[j] - '0' ||
                dict[num[j] - '0'] != num[i] - '0')
                return false;
            i++;
            j--;
        }
        if (i == j)
        {
            int digit = num[i] - '0';
            return digit == 0 || digit == 1 || digit == 8;
        }

        return true;
    }
};

void Test()
{
    Solution().isStrobogrammatic("69");
}
END_NS
