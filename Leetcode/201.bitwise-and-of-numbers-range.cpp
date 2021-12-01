/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int count = 0;
        while (left != right)
        {
            left >>= 1;
            right >>= 1;
            count++;
        }
        return left << count;
    }
};
// @lc code=end
