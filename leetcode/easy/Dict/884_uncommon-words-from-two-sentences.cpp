#include "..\..\stdafx.h"
using namespace std;
NS(884)
class Solution {
public:
    void Split(const string& input, unordered_map<string, int>& words)
    {
        stringstream ss(input);
        string w;
        while (ss >> w)
        {
            words[w] ++;
        }
    }
    void FindUncommonWord(unordered_map<string, int>& s1, unordered_map<string, int>& s2, 
        vector<string>& result)
    {
        for (auto it = s1.begin(); it != s1.end(); it++)
        {
            if (it->second == 1 && s2.find(it->first) == s2.end())
                result.push_back(it->first);
        }
    }
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> result;
        unordered_map<string, int> s1, s2;
        Split(A, s1);
        Split(B, s2);
        FindUncommonWord(s1, s2, result);
        FindUncommonWord(s2, s1, result);
        return result;
    }
};
void Test()
{
    Solution().uncommonFromSentences("this apple is sweet", "this apple is sour");
}
END_NS