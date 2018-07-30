#include <algorithm>
using namespace std;
class Solution {
public:
    int binaryGap(int N) {
        int res = 0;
        int previousOneIndex = -1;
        int index = 0;
        while (N != 0)
        {
            if (N & 0x1 == 1)
            {                
                if (previousOneIndex != -1) res = max(res, index - previousOneIndex);
                previousOneIndex = index;
            }
            N >>= 1;
            index ++;
        }

        return res;
    }
};