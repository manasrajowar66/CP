#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lli long long int
#define ll long long
#define vec vector<int>
#define for0() for (int i = 0; i < n; i++)
#define for1() for (int i = 1; i <= n; i++)
#define backloop() for (int i = n - 1; i >= 0; i--)
#define tci() \
    int t;    \
    cin >> t; \
    while (t--)
#define endl "\n"
#define Mod 1000000007
int power(int, int);
bool isPrime(int);

class TrieNode
{
public:
    TrieNode **children;
    bool isComplete;
    TrieNode()
    {
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isComplete = false;
    }
};

void insert(TrieNode *root, string s)
{
    if (s.length() == 0)
    {
        root->isComplete = true;
        return;
    }

    TrieNode *child;
    int index = s[0] - 'a';
    child = root->children[index];
    if (!child)
    {
        child = new TrieNode();
        root->children[index] = child;
    }
    insert(child, s.substr(1));
}

void makeWords(TrieNode *root, vector<string> &store, string patt)
{
    if (root->isComplete)
    {
        store.push_back(patt);
    }
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i])
        {
            char ch = 'a' + i;
            makeWords(root->children[i], store, patt + ch);
        }
    }
}

void searchText(TrieNode *root, string s, vector<string> &store)
{
    string patt;
    TrieNode *curr = root;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        patt += s[i];
        if (curr->children[s[i] - 'a'])
        {
            // if (curr->isComplete)
            // {
            //     store.push_back(patt);
            // }
            curr = curr->children[s[i] - 'a'];
        }
        else
        {
            return;
        }
    }

    // if (curr->children[s[len - 1] - 'a'])
    // {
    //     if (curr->isComplete)
    //     {
    //         patt += s[len - 1];
    //         store.push_back(patt);
    //     }
    //     curr = curr->children[s[len - 1] - 'a'];
    // }else{
    //     return;
    // }
    makeWords(curr, store, patt);
}

signed main()
{
    int n;
    cin >> n;
    TrieNode *root = new TrieNode();
    while (n--)
    {
        string s;
        cin >> s;
        insert(root, s);
    }
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        vector<string> store;
        searchText(root, s, store);
        if (store.size() == 0)
        {
            cout << "No suggestions" << endl;
            insert(root, s);
        }
        else
        {
            for (int i = 0; i < store.size(); i++)
            {
                cout << store[i] << endl;
            }
        }
    }

    return 0;
}

// My Functions //

int power(int a, int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res = (res * a);
            n--;
        }
        else
        {
            a = (a * a);
            n /= 2;
        }
    }
    return res;
}

bool isPrime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
