#include "..\..\stdafx.h"
using namespace std;
NS(544)
class Solution {
public:
    string findContestMatch(int n) {
        vector<string> strs;
        for (int i = 1; i <= n; i ++)
        {
            strs.push_back(to_string(i));
        }

        while (strs.size() > 1)
        {
            int N = strs.size();
            vector<string> other;
            for (int i = 0; i < N / 2; i ++)
            {
                other.push_back("(");
                other.back() += strs[i];
                other.back() += ",";
                other.back() += strs[N - 1 - i];
                other.back() += ")";
            }
            strs = other;
        }

        return strs[0];
    }
};

void Test() {
    vector<int> a = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
    for (int x: a)
        cout << Solution().findContestMatch(x) << endl;
}

END_NS