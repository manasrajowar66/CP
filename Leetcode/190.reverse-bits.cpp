/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;
        while (uint32_t)
        {
            ans = ans * 10 + n % 10;
            n /= 10;
        }
        return ans;
    }
};
// @lc code=end
