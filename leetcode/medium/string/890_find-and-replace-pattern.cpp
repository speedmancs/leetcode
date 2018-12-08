#include "..\..\stdafx.h"
using namespace std;
NS(890)
//class Solution2 {
//public:
//    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
//        vector<string> res;
//        for (auto& word : words)
//        {
//            if (word.size() == pattern.size() && canMap(word, pattern))
//            {
//                res.push_back(word);
//            }
//        }
//        return res;
//    }
//    bool canMap(const string& word, const string& pattern)
//    {
//        char maps[26] = {'\0'};
//        int index = 0;
//        for (char c : word)
//        {
//            if (maps[c - 'a'] == '\0')
//            {
//                maps[c - 'a'] = pattern[index];
//            }
//            else if (maps[c - 'a'] != pattern[index])
//            {
//                return false;
//            }
//            index++;
//        }
//        sort(maps, maps + 26);
//        bool hasDuplicate = false;
//        int i = 0;
//        while (i < 26)
//        {
//            int j = i + 1;
//            while (j < 26 && maps[j] == maps[i]) j++;
//            if (j - i > 1 && maps[i] != '\0') return false;
//            i = j;
//        }
//        return true;
//    }
//};

// no sorting and duplication detection
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (auto& word : words)
        {
            if (word.size() == pattern.size() && canMap(word, pattern))
            {
                res.push_back(word);
            }
        }
        return res;
    }
    bool canMap(const string& word, const string& pattern)
    {
        char maps[26] = { '\0' };
        char maps2[26] = { '\0' };
        int index = 0;
        for (char c : word)
        {
            char p = pattern[index];
            if (maps[c - 'a'] != '\0' && maps[c - 'a'] != p) return false;
            if (maps2[p - 'a'] != '\0' && maps2[p - 'a'] != c) return false;
            maps[c - 'a'] = p;               
            maps2[p - 'a'] = c;
            index++;
        }

        return true;
    }
};
END_NS
