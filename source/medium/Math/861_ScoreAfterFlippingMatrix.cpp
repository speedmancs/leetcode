#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
class Solution {
public:
    void FlipRow(vector<vector<int>>& A, int row)
    {
        for (int& x : A[row])
        {
            x = 1 - x;            
        }
    }

    int FindInCol(vector<vector<int>>& A, int col, int number)
    {
        int cnt = 0;
        for (auto& v: A)
        {
            if (number == v[col]) cnt ++;
        }
        return cnt;
    }

    int matrixScore(vector<vector<int>>& A) {
        int Rows = A.size();
        int Cols = A[0].size();
        int result = 0;
        for (int i = 0; i < Rows; i ++)
        {
            if (A[i][0] == 0) FlipRow(A, i);
            result += 1 << (Cols - 1);
        }

        for (int i = 1; i < Cols; i ++)
        {
            int ones = FindInCol(A, i, 1);
            int count = max(ones, Rows - ones);
            result += count * (1 << (Cols - 1 - i));
        }
        return result;        
    }
};