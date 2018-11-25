#include "..\..\stdafx.h"
using namespace std;
NS(933)
class RecentCounter {
public:
    RecentCounter() {

    }

    int ping(int t) {
        while (!q.empty() && q.front() < t - 3000) q.pop();
        q.push(t);
        return q.size();
    }
    queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
END_NS
