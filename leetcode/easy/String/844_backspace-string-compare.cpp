#include "..\..\stdafx.h"
using namespace std;
NS(844)
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int index1, index2;
        transform(S, index1);
        transform(T, index2);
        if (index1 != index2) return false;
        for (int i = 0; i < index1; i++)
        {
            if (S[i] != T[i]) return false;
        }
        return true;
    }
    void transform(string& str, int& index)
    {
        index = 0;
        for (auto c : str)
        {
            if (c == '#')
            {
                if (index > 0) index--;
            }
            else
            {
                str[index++] = c;
            }
        }
    }
};
END_NS
