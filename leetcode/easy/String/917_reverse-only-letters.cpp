#include "..\..\stdafx.h"
using namespace std;
NS(917)
class Solution {
public:
    string reverseOnlyLetters(string S) {
        string result = S;
        int n = result.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            while (i < n && !isalpha(result[i])) i++;
            if (i == n) break;
            while (j >= 0 && !isalpha(result[j])) j--;
            if (j < 0) break;
            if (i < j) swap(result[i++], result[j--]);
        }
        return result;
    }
};
END_NS