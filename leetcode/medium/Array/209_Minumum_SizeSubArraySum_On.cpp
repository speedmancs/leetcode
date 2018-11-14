#include "..\..\stdafx.h"
using namespace std; 
NS(209)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int left = 0;
        int right = 0;
        // a[left: right], right is fixed, move forward left
        // as left is the first index in range[0: right] so that sum(a[left: right]) < s
        int ans = INT_MAX;
        int sum = nums[0];
        while (right < n)
        {
            while (left <= right && sum >= s)
            {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left ++;
            }            
            right ++;
            if (right < n) sum += nums[right];
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
END_NS