/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
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

class WordDictionary
{
private:
    Trie *root = NULL;
    bool search_helper(string word, int i, Trie *currNode)
    {
        if (i == word.size())
        {
            return currNode->isEndHere;
        }
        if (word[i] != '.')
        {
            int index = word[i] - 'a';
            if (!currNode->alpha[index])
            {
                return false;
            }
            return search_helper(word, i + 1, currNode->alpha[index]);
        }
        else
        {
            for (int j = 0; j < 26; j++)
            {
                if (currNode->alpha[j] && search_helper(word, i + 1, currNode->alpha[j]))
                {
                    return true;
                }
            }
            return false;
        }
    }

public:
    WordDictionary()
    {
        root = new Trie();
    }

    void addWord(string word)
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

    bool search(string word)
    {
        return search_helper(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
