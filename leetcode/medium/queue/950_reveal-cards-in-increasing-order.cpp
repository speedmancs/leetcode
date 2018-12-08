#include "..\..\stdafx.h"
using namespace std;
NS(950)
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        if (deck.size() < 2) return deck;
        sort(deck.begin(), deck.end());
        deque<int> q;
        q.push_back(deck.back());
        deck.pop_back();
        vector<int> result;
        while (!deck.empty())
        {
            q.push_front(q.back());
            q.pop_back();
            q.push_front(deck.back());
            deck.pop_back();
        }
        while (!q.empty())
        {
            result.push_back(q.front());
            q.pop_front();
        }
        return result;
    }
};
END_NS