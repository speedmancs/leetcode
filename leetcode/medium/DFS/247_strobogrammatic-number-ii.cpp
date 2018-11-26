#include "..\..\stdafx.h"
using namespace std;
NS(247)
//class Solution {
//public:
//    vector<string> candidates;
//    vector<string> findStrobogrammatic(int n) {
//        candidates = { "00", "11", "88", "69", "96" };
//        vector<string> result;
//        if (n == 1)
//        {
//            result.push_back("0");
//            result.push_back("1");
//            result.push_back("8");
//            return result;
//        }
//        go(n, false, result);
//        return result;
//    }
//
//    void go(int n, bool leadingZero, vector<string>& result)
//    {
//        if (n == 1)
//        {
//            result.push_back("1");
//            result.push_back("8");
//            if (leadingZero) result.push_back("0");
//            return;
//        }
//        if (n == 2)
//        {
//            for (auto& candidate : candidates)
//            {
//                if (candidate[0] == '0' && !leadingZero) continue;
//                result.push_back(candidate);
//            }
//            return;
//        }
//
//        vector<string> result2;
//        go(n - 2, true, result2);
//        for (auto& candidate: candidates)
//        {
//            if (candidate[0] == '0' && !leadingZero) continue;
//            for (auto& str : result2)
//            {
//                string newStr;
//                newStr += candidate[0];
//                newStr += str;
//                newStr += candidate[1];
//                result.push_back(newStr);
//            }
//        }
//    }
//};

// DFS
class Solution {
public:
    vector<string> results;
    string candidate;
    int N;
    string validDigits;
    string validDoubleDigits;
    vector<string> findStrobogrammatic(int n) {
        if (n == 1)
        {
            results = { "0", "1", "8" };
            return results;
        }
        validDigits = "018";
        validDoubleDigits = "0011886996";
        N = n;
        candidate.resize(n);
        Go(0);
        return results;
    }

    void Go(int start)
    {
        int len = N - (start << 1);
        if (len == 0)
        {
            results.push_back(candidate);
            return;
        }

        if (len == 1)
        {
            for (char c : validDigits)
            {
                candidate[start] = c;
                results.push_back(candidate);
            }
            return;
        }
        
        for (int i = 0; i < 10; i+=2)
        {
            if (start == 0 && i == 0) continue;
            candidate[start] = validDoubleDigits[i];
            candidate[len - 1 + start] = validDoubleDigits[i + 1];
            Go(start + 1);
        }
    }
};
END_NS