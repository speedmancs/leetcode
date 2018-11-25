#include "..\..\stdafx.h"
using namespace std;
NS(944)
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int result = 0;
        int row = A.size();
        if (row == 0) return 0;
        int col = A[0].size();
        for (int c = 0; c < col; c++)
        {
            for (int i = 0; i < row - 1; i++)
            {
                if (A[i + 1][c] < A[i][c])
                {
                    result++;
                    break;
                }
            }
        }
        return result;
    }
};
END_NS