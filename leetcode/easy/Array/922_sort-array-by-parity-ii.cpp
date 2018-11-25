#include "..\..\stdafx.h"
using namespace std;
NS(922)
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int oddIndex = 1;
        int evenIndex = 0;
        int n = A.size();
        while (oddIndex < n && evenIndex < n)
        {
            while ((A[oddIndex] & 1) && oddIndex < n) oddIndex+=2;
            while ((A[evenIndex] & 1) == 0 && evenIndex < n) evenIndex+=2;
            if (oddIndex < n && evenIndex < n)
            {
                swap(A[oddIndex], A[evenIndex]);
                oddIndex += 2;
                evenIndex += 2;
            }
        }
        return A;
    }
};
END_NS