#include "..\..\stdafx.h"
using namespace std;
NS(941)
// O(n)
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if (n < 3) return false;
        int i = 1;
        while (i < n && A[i] > A[i - 1]) i++;
        if (i == n || i == 1) return false;
        // A[i] <= A[i - 1]
        int j = i - 1;
        while (j < n - 1 && A[j] > A[j + 1]) j++;
        return j == n - 1;
    }
};
END_NS