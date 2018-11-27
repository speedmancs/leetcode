#include "..\..\stdafx.h"
using namespace std;
NS(849)
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int start = 0;        
        while (seats[start] == 0) start++;
        int res = start;
        int end = n - 1;
        while (seats[end] == 0) end--;
        res = max(res, n - end - 1);

        for (int i = start + 1; i < end;)
        {
            if (seats[i] == 1)
            {
                i++;
                continue;
            }
            int j = i;
            while (seats[j] == 0) j++;
            res = max(res, (j - i + 1) / 2);
            i = j + 1;
        }
        return res;
    }
};
END_NS