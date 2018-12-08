#include "..\..\stdafx.h"
using namespace std;
NS(921)
class Solution {
public:
    int minAddToMakeValid(string S) {
        int open = 0;
        int result = 0;
        int n = S.size();
        for (int i = 0; i < n; i ++)
        {
            if (S[i] == '(') open++;
            else
            {
                if (open > 0) open--;
                else result++;
            }
        }
        result += open;
        return result;
    }
};
END_NS
