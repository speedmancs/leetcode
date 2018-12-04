#include "..\..\stdafx.h"
using namespace std;
NS(408)
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;
        int j = 0;
        while (i < word.size() && j < abbr.size())
        {
            if (isalpha(abbr[j]))
            {
                if (word[i] == abbr[j])
                {
                    i++; j++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                int start = j;
                if (abbr[start] == '0') return false;
                while (j < abbr.size() && isdigit(abbr[j])) j++;
                int len = stoi(abbr.substr(start, j - start));
                if (word.size() - i < len) return false;
                i += len;
            }
        }

        return i == word.size() && j == abbr.size();
    }
};
END_NS
