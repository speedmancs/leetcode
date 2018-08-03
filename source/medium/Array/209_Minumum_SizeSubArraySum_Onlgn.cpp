#include <vector>
#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int ans = INT_MAX;
        vector<int> sum(n + 1, 0);
        sum[1] = nums[0];
        for (int i = 2; i <= n; i ++)
            sum[i] = sum[i - 1] + nums[i - 1];

        for (int i = 0; i < n; i ++)
        {
            cout << "i:" << i << endl;
            auto it = lower_bound(sum.begin() + i + 1, sum.end(), s + sum[i]);
            if (it != sum.end())
            {
                int k = it - sum.begin();
                ans = min(ans, k - i);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

int main()
{
    vector<int> a = {1,4,4};
    cout << Solution().minSubArrayLen(4, a) << endl;
}