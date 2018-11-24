#include "..\..\stdafx.h"
using namespace std;
NS(896)
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = std::accumulate(A.begin(), A.end(), 0);
        int sumB = std::accumulate(B.begin(), B.end(), 0);
        int diff = abs(sumA - sumB) / 2;
        if (sumA > sumB)
        {
            return _fairCandySwap(A, B, diff);
        }
        else
        {
            auto v = _fairCandySwap(B, A, diff);
            swap(v[0], v[1]);
            return v;
        }
    }
    vector<int> _fairCandySwap(vector<int>& A, vector<int>& B, int diff)
    {
        unordered_set<int> setB;
        for (auto x : B) setB.insert(x);
        vector<int> result(2);
        for (auto x : A)
        {
            if (setB.find(x - diff) != setB.end())
            {
                result[0] = x;
                result[1] = x - diff;
                break;
           }
        }
        return result;
    }
};
END_NS