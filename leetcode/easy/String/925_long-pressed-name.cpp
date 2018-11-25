#include "..\..\stdafx.h"
using namespace std;
NS(925)
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int n = name.size();
        int m = typed.size();
        int j = 0;
        while (i < n && j < m)
        {
            if (name[i] != typed[j]) return false;
            int i1 = i;
            int j1 = j;
            while (i1 < n && name[i1] == name[i]) i1++;
            while (j1 < m && typed[j1] == typed[j]) j1++;
            if (i1 - i > j1 - j) return false;
            i = i1;
            j = j1;
        }

        return i == n && j == m;
    }
};
END_NS
