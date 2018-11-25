#include "..\..\stdafx.h"
using namespace std;
NS(703)
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int K;
    KthLargest(int k, vector<int> nums) {
        K = k;
        for (auto x : nums)
        {
            AddQueue(x);
        }
    }

    void AddQueue(int val)
    {
        if (q.size() < K)
        {
            q.push(val);
            return;
        }

        if (val <= q.top()) return;
        q.pop();
        q.push(val);
    }

    int add(int val) {
        AddQueue(val);
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
END_NS
