#include "..\..\stdafx.h"
using namespace std;
NS(949)
class Solution {
public:
    vector<int> times;
    vector<bool> used;
    vector<int> candidates;
    int MAX_TIME;
    string largestTimeFromDigits(vector<int>& A) {
        candidates = A;
        MAX_TIME = INT_MIN;
        times = vector<int>(4);
        used = vector<bool>(4, false);
        Go(0);
        if (MAX_TIME == INT_MIN) return "";
        char buf[6] = {};
        sprintf(buf, "%02d:%02d", MAX_TIME / 60, MAX_TIME % 60);
        return string(buf);
    }

    void Go(int pos)
    {
        if (pos == 4)
        {
            int newTime = (times[0] * 10 + times[1]) * 60 + times[2] * 10 + times[3];
            if (newTime > MAX_TIME)
            {
                MAX_TIME = newTime;
            }
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            if (used[i]) continue;
            if (pos == 0 && candidates[i] >= 3) continue;
            if (pos == 1 && times[0] == 2 && candidates[i] >= 4) continue;
            if (pos == 2 && candidates[i] >= 6) continue;
            times[pos] = candidates[i];
            used[i] = true;
            Go(pos + 1);
            used[i] = false;
        }
    }
};
END_NS
