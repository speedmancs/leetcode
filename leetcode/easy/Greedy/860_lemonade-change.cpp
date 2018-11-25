#include "..\..\stdafx.h"
using namespace std;
NS(860)
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveNote = 0;
        int tenNote = 0;
        for (auto x : bills)
        {
            if (x == 5) fiveNote++;
            else if (x == 10)
            {
                if (fiveNote == 0) return false;
                fiveNote--;
                tenNote++;
            }
            else
            {
                if (tenNote > 0 && fiveNote > 0)
                {
                    tenNote--; fiveNote--;
                }
                else if (fiveNote >= 3)
                {
                    fiveNote -= 3;
                }
                else
                {
                    return false;
                }
            }

        }
        return true;
    }
};
END_NS