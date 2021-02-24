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

string s, t;
string LCS()
{
    const int n = s.length(), m = t.length();
    int val[n + 1][m + 1];
    char pattern[n][m];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                val[i][j] = 0;
            }
            else if (s[i - 1] == t[j - 1])
            {
                val[i][j] = 1 + val[i - 1][j - 1];
                pattern[i - 1][j - 1] = 'C';
            }
            else
            {
                if (val[i][j - 1] > val[i - 1][j])
                {
                    val[i][j] = val[i][j - 1];
                    pattern[i - 1][j - 1] = 'L';
                }
                else
                {
                    val[i][j] = val[i - 1][j];
                    pattern[i - 1][j - 1] = 'U';
                }
            }
        }
    }
    int i = n - 1, j = m - 1;
    string res;
    while (i >= 0 && j >= 0)
    {
        if (pattern[i][j] == 'C')
        {
            res += s[i];
            i--;
            j--;
        }
        else if (pattern[i][j] == 'L')
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    return res;
}

signed main()
{
    cin >> s >> t;
    string res = LCS();
    reverse(res.begin(), res.end());
    cout << res;
    return 0;
}
