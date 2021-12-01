/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> res;
        unordered_map<string, int> DNA;
        int n = s.length(), i = 0;

        while (i + 10 <= n)
        {
            DNA[s.substr(i++, 10)]++;
        }
        for (auto &it : DNA)
        {
            if (it.second > 1)
                res.push_back(it.first);
        }
        return res;
    }
};
// @lc code=end
