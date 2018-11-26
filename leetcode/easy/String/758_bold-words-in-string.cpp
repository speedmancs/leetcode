#include "..\..\stdafx.h"
using namespace std;
NS(758)
class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        int n = S.size();
        vector<bool> shouldBold(n, false);
        for (auto& w : words)
        {
            int i = 0;
            while (i < n)
            {
                int index = S.find(w.c_str(), i);
                if (index == string::npos) break;
                for (int j = index; j < index + w.size(); j++)
                    shouldBold[j] = true;
                i = index + 1;
            }
        }

        string result;
        int i = 0;
        while (i < n)
        {
            int j = i;
            while (j < n && !shouldBold[j])
            {
                result += S[j++];
            }
            if (j == n) break;
            // S[j] should be bold
            result += "<b>";
            while (j < n && shouldBold[j])
            {
                result += S[j++];
            }
            result += "</b>";
            i = j;
        }
        return result;
    }
};
END_NS