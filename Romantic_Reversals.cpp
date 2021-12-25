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

string solve(string s, int n, int k)
{
    if (k == 1)
        return s;
    string ans = s;
    int l = 0, h = k - 1, ind = k - 1;
    while (l <= h)
    {
        if (l == h)
        {
            ans[ind--] = s[l];
        }
        else
        {
            ans[ind--] = s[l];
            ans[ind--] = s[h];
        }
        l++;
        h--;
    }
    return ans;
}

signed main()
{
    tci()
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        cout << solve(s, n, k) << endl;
    }
    return 0;
}
