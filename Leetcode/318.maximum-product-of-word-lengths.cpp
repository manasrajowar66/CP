/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */

// @lc code=start
class Solution
{
private:
    vector<pair<int, int>> bits_rep;
    int convertStringToBits(string s)
    {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            ans = ans | (1 << (s[i] - 'a'));
        }
        return ans;
    }

public:
    int maxProduct(vector<string> &words)
    {
        int n = words.size();
        bits_rep.resize(n);
        for (int i = 0; i < n; i++)
        {
            bits_rep[i].first = convertStringToBits(words[i]);
            bits_rep[i].second = words[i].size();
        }
        int max_prod = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((bits_rep[i].first & bits_rep[j].first) == 0)
                {
                    max_prod = max(max_prod, bits_rep[i].second * bits_rep[j].second);
                }
            }
        }
        return max_prod;
    }
};
// @lc code=end
