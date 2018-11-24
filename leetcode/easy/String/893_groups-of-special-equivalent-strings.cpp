#include "..\..\stdafx.h"
using namespace std;
NS(893)
class Solution {
public:
    string temp0;
    string temp1;
    int numSpecialEquivGroups(vector<string>& A) {
        int len = A[0].size();
        temp0.resize((len + 1) / 2);
        temp1.resize(len - (len + 1)/ 2);
        for (auto& str : A)
            transform(str);
        sort(A.begin(), A.end());
        int count = 0;
        int i = 0;
        int n = A.size();
        while (i < n)
        {
            count++;
            int j = i + 1;
            while (j < n && A[j] == A[i]) j++;
            i = j;
        }
        return count;
    }

    void transform(string& str)
    {
        int n = str.size();
        
        for (int i = 0; i < n; i += 2)
        {
            temp0[i >> 1] = str[i];
        }
        sort(temp0.begin(), temp0.end());
        for (int i = 0; i < n; i += 2)
        {
            str[i] = temp0[i >> 1];
        }
        for (int i = 1; i < n; i += 2)
        {
            temp1[(i - 1) >> 1] = str[i];
        }
        sort(temp1.begin(), temp1.end());
        for (int i = 1; i < n; i += 2)
        {
             str[i] = temp1[(i - 1) >> 1];
        }
    }
};
void Test()
{
    vector<string> vec = { "abc","acb","bac","bca","cab","cba" };
    cout << Solution().numSpecialEquivGroups(vec) << endl; 
}
END_NS
