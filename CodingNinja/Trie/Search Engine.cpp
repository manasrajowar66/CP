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
    TrieNode *alpha[26];
    int weight;
    TrieNode()
    {
        weight = 0;
        for (int i = 0; i < 26; i++)
        {
            alpha[i] = NULL;
        }
    }
};

void insert(TrieNode *head, string s, int w)
{
    int len = s.length();
    TrieNode *curr = head;
    for (int i = 0; i < len; i++)
    {
        if (curr->alpha[s[i] - 'a'] == NULL)
        {
            curr->alpha[s[i] - 'a'] = new TrieNode();
        }
        curr->alpha[s[i] - 'a']->weight = max(curr->alpha[s[i] - 'a']->weight, w);
        curr = curr->alpha[s[i] - 'a'];
    }
}

int query(TrieNode *head, string s)
{
    int len = s.length();
    TrieNode *curr = head;
    for (int i = 0; i < len; i++)
    {
        if (curr->alpha[s[i] - 'a'] == NULL)
        {
            return -1;
        }
        curr = curr->alpha[s[i] - 'a'];
    }
    for (int i = 0; i < 26; i++)
    {
        if (curr->alpha[i] != NULL)
        {
            return curr->weight;
        }
    }
    return -1;
}

signed main()
{
    int n, q;
    cin >> n >> q;
    TrieNode *head = new TrieNode();
    for (int i = 0; i < n; i++)
    {
        string s;
        int w;
        cin >> s >> w;
        insert(head, s, w);
    }
    while (q--)
    {
        string s;
        cin >> s;
        cout << query(head, s) << endl;
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
