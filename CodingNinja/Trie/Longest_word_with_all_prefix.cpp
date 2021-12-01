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
class Trie
{
public:
    bool isEndHere;
    int size;
    string s;
    vector<Trie *> alpha;
    Trie()
    {
        alpha.resize(26, NULL);
        isEndHere = false;
        size = 0;
        s = "";
    }
};
int maxi;
string pre;
void insert(Trie *root, string word)
{
    int n = word.size();
    for (int i = 0; i < n; i++)
    {
        int index = word[i] - 'a';
        if (root->alpha[index])
        {
            root = root->alpha[index];
        }
        else
        {
            root->alpha[index] = new Trie();
            root = root->alpha[index];
        }
    }
    root->isEndHere = true;
    root->size = n;
    root->s = word;
}
void search(Trie *root)
{
    if (root && root->isEndHere && maxi < root->size)
    {
        maxi = root->size;
        pre = root->s;
    }
    else
    {
        return;
    }
    for (int i = 0; i < 26; i++)
    {
        search(root->alpha[i]);
    }
}
string completeString(int n, vector<string> &a)
{
    // Write your code here
    Trie *root = new Trie();
    for (int i = 0; i < n; i++)
    {
        insert(root, a[i]);
    }
    maxi = 0;
    pre = "";
    for (int i = 0; i < 26; i++)
    {
        search(root->alpha[i]);
    }
    if (pre == "")
        return "None";
    return pre;
}
signed main()
{
    tci()
    {
        int n;
        cin >> n;
        vector<string> words(n);
        for (int i = 0; i < n; i++)
        {
            cin >> words[i];
        }
        cout << completeString(n, words) << endl;
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
