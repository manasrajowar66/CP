#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lli long long int
#define ll long long
#define vec vector<int>
#define for0() for (int i = 0; i < n; i++)
#define for1() for (int i = 1; i <= n; i++)
#define backloop() for (int i = n - 1; i >= 0; i--)
#define ff first
#define ss second
#define tci() \
    int t;    \
    cin >> t; \
    while (t--)
#define endl "\n"
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void LPS(string s, int lps[])
{
    int len = s.length();
    lps[0] = 0;
    int i = 0, j = 1;
    while (j < len)
    {
        if (s[i] == s[j])
        {
            lps[j] = i + 1;
            j++;
            i++;
        }
        else
        {
            if (i == 0)
            {
                lps[j] = 0;
                j++;
            }
            else
            {
                i = lps[i - 1];
            }
        }
    }
}

void solve()
{
    string text, ptr;
    getline(cin, text);
    cin >> ptr;
    int n = text.length();
    int m = ptr.length();
    int lps[m];
    LPS(ptr, lps);
    int i = 0, j = 0;
    while (i < n)
    {
        if (text[i] == ptr[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << i - j << " ";
            j = lps[j - 1];
        }
        else if (i < n && text[i] != ptr[j])
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
}

signed main()
{
    solve();
    return 0;
}
