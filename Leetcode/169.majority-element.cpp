/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < 32; i++)
        {
            int count = 0, shift = (1 << i);
            for (int j = 0; j < n; j++)
            {
                if (nums[j] & shift)
                {
                    count++;
                }
            }
            if (count > (n / 2))
            {
                ans = ans | shift;
            }
        }
        return ans;
    }
};
// @lc code=end
