#include "..\..\stdafx.h"
using namespace std; 
NS(830)
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;
        int start = 0;
        int N = S.size();
        while (start < N)
        {
            int j = start + 1;
            while (j < N && S[j] == S[start]) j ++;
            if (j - start >= 3)
            {
                vector<int> t = {start, j - 1};
                result.push_back(t);
            }
            start = j;
        }
        return result;
    }
};
END_NS