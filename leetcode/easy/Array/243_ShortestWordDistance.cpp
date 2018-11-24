#include "..\..\stdafx.h"
using namespace std;
NS(243)
//class Solution {
//public:
//    int shortestDistance(vector<string>& words, string word1, string word2) {
//        vector<int> indexes;
//        vector<int> indexes2;
//        int i = 0;
//        for (auto& w : words)
//        {
//            if (w == word1)
//                indexes.push_back(i);
//            if (w == word2)
//                indexes2.push_back(i);
//            i++;
//        }
//
//        int minDis = INT_MAX;
//        for (int index : indexes2)
//        {
//            // *it >= index
//            auto it = lower_bound(indexes.begin(), indexes.end(), index);
//            if (it == indexes.end())
//            {
//                minDis = min(minDis, index - indexes.back());
//            }
//            else
//            {
//                // *(it - 1) < index < *it
//                minDis = min(minDis, *it - index);
//                if (it != indexes.begin())
//                    minDis = min(minDis, index - *(it - 1));
//            }
//        }
//        return minDis;
//    }
//};

//class Solution {
//public:
//    int shortestDistance(vector<string>& words, string word1, string word2) {
//        int minDis = INT_MAX;
//        minDis = min(minDis, MinDistance(words, word1, word2));
//        minDis = min(minDis, MinDistance(words, word2, word1));
//        return minDis;
//    }
//
//    int MinDistance(vector<string>& words, string& word1, string& word2)
//    {
//        int minDis = INT_MAX;
//        int n = words.size();
//        int i = 0;
//        int j = n - 1;
//        while (i < n && words[i] != word1) i++;
//        while (j >= 0 && words[j] != word2) j--;
//
//        // words[i] = word1
//        // words[j] = word2
//        while (i < j)
//        {
//            int start = i;
//            int end = j;
//            minDis = min(minDis, j - i);
//            i++;
//            while (i < end && words[i] != word1) i++;
//            j--;
//            while (j > start && words[j] != word2) j--;
//            if (i < j) continue;
//            if (i == end && j != start)
//            {
//                i = start;
//            }
//            else if (i != end && j == start)
//            {
//                j = end;
//            }
//            else if (i != end && j != start)
//            {
//                i = end;
//                while (words[i] != word1) i--;
//                minDis = min(minDis, end - i);
//                j = start;
//                while (words[j] != word2) j++;
//                minDis = min(minDis, j - start);
//                break;
//            }
//        }
//        return minDis;
//    }
//};

// O(n)
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int minDis = INT_MAX;
        int n = words.size();
        int pos1 = -1;
        int pos2 = -1;
        for (int i = 0; i < n; i++)
        {
            if (words[i] == word1) pos1 = i;
            else if (words[i] == word2) pos2 = i;
            else continue;
            if (pos1 != -1 && pos2 != -1 && abs(pos1 - pos2) < minDis)
                minDis = abs(pos1 - pos2);
        }
        return minDis;
    }
};
END_NS
