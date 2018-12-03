#include "..\..\stdafx.h"
using namespace std;
NS(914)
class Solution {
public:
    int gcd(int a, int b)
    {
        if (a < b)
        {
            swap(a, b);
        }
        // a >= b
        while (true)
        {
            int r = a % b;
            if (r == 0) return b;
            a = r;
            swap(a, b);
        }
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> count;
        for (auto x : deck)
        {
            count[x] ++;
        }
        if (count.size() == 1)
        {
            return deck.size() >= 2;
        }

        auto it = count.begin();
        int result = it->second;
        it++;
        while (it != count.end())
        {
            result = gcd(result, it->second);
            it++;
        }
        return result != 1;
    }
};
END_NS