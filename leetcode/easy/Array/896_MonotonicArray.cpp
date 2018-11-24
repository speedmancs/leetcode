#include "..\..\stdafx.h"
using namespace std;
NS(896)
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        if (n < 3) return true;
        int i = 0;
        while (i < n - 1 && A[i] == A[i + 1]) i++;
        if (i == n - 1) return true;
        // A[i] != A[i + 1]

        // case 1, A[i] > A[i + 1]
        if (A[i] > A[i + 1])
        {
            i++;
            while (i < n - 1 && A[i] >= A[i + 1]) i++;
            return i == n - 1;
        }
        // case 2, A[i] < A[i + 1]
        else
        {
            i++;
            while (i < n - 1 && A[i] <= A[i + 1]) i++;
            return i == n - 1;
        }
    }
};
END_NS