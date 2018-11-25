#include "..\..\stdafx.h"
using namespace std;
NS(942)
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n = S.size();
        int smallest = 0;
        int largest = n;
        vector<int> r(n + 1);
        
        int index = 0;
        for (auto i : S)
        {
            if (i == 'I')
            {
                r[index++] = smallest++;
            }
            else
            {
                r[index++] = largest--;
            }
        }
        r[index] = smallest;
        return r;
    }
};
END_NS