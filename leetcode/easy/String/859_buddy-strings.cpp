#include "..\..\stdafx.h"
using namespace std;
NS(859)
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        int n = A.size();
        int map[26] = { 0 };
        int count = 0;
        int index1 = -1;
        int index2 = -1;
        for (int i = 0; i < n; i++)
        {
            if (A[i] != B[i])
            {
                if (index1 == -1) index1 = i;
                else if (index2 == -1) index2 = i;
                count++;
            }
            if (count > 2) return false;
            map[A[i] - 'a'] ++;
        }

        if (count > 2 || count == 1) return false;
        if (count == 2)
        {
            return A[index1] == B[index2] && A[index2] == B[index1];
        }

        //count == 0
        for (int i = 0; i < 26; i++)
        {
            if (map[i] > 1) return true;
        }
        return false;
    }
};
END_NS
