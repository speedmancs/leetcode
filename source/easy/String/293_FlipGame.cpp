#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        if (s.empty()) return result;
        for (int i = 0; i < s.size() - 1; i ++)
        {
            if (s[i] == s[i + 1] && s[i] == '+')
            {
                s[i] = s[i + 1] = '-';
                result.push_back(s);
                s[i] = s[i + 1] = '+';
            }
        }
        return result;
    }
};