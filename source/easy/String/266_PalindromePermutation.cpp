#include <string>
using namespace std;
class Solution {
public:
    bool canPermutePalindrome(string s) {
        bool single[256];
        memset(single, 0, 256 * sizeof(bool));
        int singleCount = 0;
        for (auto c: s)
        {
            int idx = (unsigned char)c;
            single[idx] = !single[idx];
        }
        for (int i = 0; i < 256; i ++)
        {
            if (single[i]) singleCount ++;
        }

        return singleCount <= 1;
    }
};