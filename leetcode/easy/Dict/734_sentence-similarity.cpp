#include "..\..\stdafx.h"
using namespace std;
NS(734)

struct pair_hash
{
    inline size_t operator()(const pair<string, string>& v) const {
        return std::hash<string>()(v.first) * 31 + std::hash<string>()(v.second);
    }
};
class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        unordered_set<pair<string, string>, pair_hash> set;
        for (auto& v : pairs) set.insert(v);
        int n = words1.size();
        for (int i = 0; i < n; i++)
        {
            if (words1[i] != words2[i] &&
                set.find(make_pair(words1[i], words2[i])) == set.end() &&
                set.find(make_pair(words2[i], words1[i])) == set.end())
                return false;
        }
        return true;
    }
};
END_NS
