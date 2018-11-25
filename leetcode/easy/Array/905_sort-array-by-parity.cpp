#include "..\..\stdafx.h"
using namespace std;
NS(905)
// stable_sort
//class Solution {
//public:
//    vector<int> sortArrayByParity(vector<int>& A) {
//        stable_sort(A.begin(), A.end(), [](int a, int b) {
//            if (a % 2 == 0 && b % 2 == 1) return true;
//            return false;
//        });
//        return A;
//    }
//};

// use sort
//class Solution {
//public:
//    vector<int> sortArrayByParity(vector<int>& A) {
//        sort(A.begin(), A.end(), [](int a, int b) {
//            if (a % 2 == 0 && b % 2 == 1) return true;
//            return false;
//        });
//        return A;
//    }
//};

// O(n)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int i = 0;
        int j = n - 1;
        while (i <= j)
        {
            while ((A[i] & 1) == 0 && i <= j) i++;
            if (i > j) break;
            // A[i] is odd
            while ((A[j] & 1) && i <= j) j--;
            if (i > j) break;
            // A[j] is even
            swap(A[i++], A[j--]);
        }
        return A;
    }
};
void Test()
{
    vector<int> v = { 0,1,2 };
    Solution().sortArrayByParity(v);
}
END_NS
