/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */

// @lc code=start
class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        queue<int> q;
        int n = dominoes.size();
        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] != '.')
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int size = q.size();
            string temp = dominoes;
            for (int i = 0; i < size; i++)
            {
                int front = q.front();
                q.pop();
                if (dominoes[front] == 'R' && front + 1 < n && dominoes[front + 1] == '.')
                {
                    if (front + 2 < n && dominoes[front + 2] == 'L')
                    {
                        continue;
                    }
                    else
                    {
                        temp[front + 1] = 'R';
                        q.push(front + 1);
                    }
                }
                else if (dominoes[front] == 'L' && front - 1 >= 0 && dominoes[front - 1] == '.')
                {
                    if (front - 2 >= 0 && dominoes[front - 2] == 'R')
                    {
                        continue;
                    }
                    else
                    {
                        temp[front - 1] = 'L';
                        q.push(front - 1);
                    }
                }
            }
            dominoes = temp;
        }
        return dominoes;
    }
};
// @lc code=end
