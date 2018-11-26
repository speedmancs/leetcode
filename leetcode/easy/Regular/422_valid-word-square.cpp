#include "..\..\stdafx.h"
using namespace std;
NS(422)
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int row = words.size();
        for (int r = 0; r < row; r++)
        {
            if (words[r].size() > row) return false;
            for (int c = 0; c < words[r].size(); c++)
            {
                if (r >= words[c].size() || words[r][c] != words[c][r])
                    return false;
            }
            for (int c = words[r].size(); c < row; c++)
            {
                if (r < words[c].size()) return false;
            }
        }

        return true;
    }
};
END_NS