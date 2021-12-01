/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            ans ^= nums[i];
        }
        return ans;
    }
};
// @lc code=end
