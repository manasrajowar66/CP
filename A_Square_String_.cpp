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

string solve()
{
    string s;
    cin >> s;
    int n = s.length();
    if (n % 2 == 1)
    {
        return "NO";
    }
    else
    {
        int i = 0, mid = n / 2;
        while (mid < n)
        {
            if (s[i] != s[mid])
                return "NO";
            i++;
            mid++;
        }
        return "YES";
    }
}

signed main()
{
    tci()
    {
        cout << solve() << endl;
    }
    return 0;
}
