/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < 32; i++)
        {
            int count = 0;
            int shift = 1 << i;
            for (int j = 0; j < n; j++)
            {
                if (nums[j] & shift)
                {
                    count++;
                }
            }
            if (count % 3)
            {
                ans = ans | shift;
            }
        }
        return ans;
    }
};
// @lc code=end
