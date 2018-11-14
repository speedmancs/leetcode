#include "..\..\stdafx.h"
using namespace std;
NS(867)
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int Rows = A.size();
        int Cols = A[0].size();
        vector<vector<int>> result(Cols, vector<int>(Rows, 0));
        for (int i = 0; i < Rows; i ++)
            for (int j = 0; j < Cols; j ++)
                result[j][i] = A[i][j];
        return result;
    }    
};
END_NS