#include "..\..\stdafx.h"
using namespace std;
NS(704)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        // [left, right)
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) right = mid;
            else left = mid + 1;
        }
        return -1;
    }
};
END_NS
