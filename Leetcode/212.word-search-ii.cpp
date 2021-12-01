/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Trie
{
public:
    bool isEndHere;
    vector<Trie *> alpha;
    Trie()
    {
        isEndHere = false;
        alpha.resize(26, NULL);
    }
};
class Solution
{
private:
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int n, m;
    Trie *root;
    void insert(string word)
    {
        int n = word.size();
        Trie *curr = root;
        for (int i = 0; i < n; i++)
        {
            int index = word[i] - 'a';
            if (curr->alpha[index])
            {
                curr = curr->alpha[index];
            }
            else
            {
                curr->alpha[index] = new Trie();
                curr = curr->alpha[index];
            }
        }
        curr->isEndHere = true;
    }

    void helper(int x, int y, vector<vector<char>> &board, vector<string> &res, Trie *curr, string s)
    {
        if (!curr)
        {
            return;
        }
        if (curr->isEndHere)
        {
            res.push_back(s);
            curr->isEndHere = false;
        }
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dir[i][0];
            int newy = y + dir[i][1];
            if (newx >= 0 && newx < n && newy >= 0 && newy < m && board[newx][newy] != '$')
            {
                char temp = board[newx][newy];
                int index = temp - 'a';
                board[newx][newy] = '$';
                if (curr->alpha[index])
                {
                    helper(newx, newy, board, res, curr->alpha[index], s + temp);
                }
                board[newx][newy] = temp;
            }
        }
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        root = new Trie();
        int words_size = words.size();
        for (int i = 0; i < words_size; i++)
        {
            insert(words[i]);
        }
        vector<string> res;
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int index = board[i][j] - 'a';
                string s;
                s += board[i][j];
                if (root->alpha[index])
                {
                    char temp = board[i][j];
                    board[i][j] = '$';
                    helper(i, j, board, res, root->alpha[index], s);
                    board[i][j] = temp;
                }
                        }
        }
        return res;
    }
};
// @lc code=end
