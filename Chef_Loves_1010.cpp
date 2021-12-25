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

signed main()
{
    tci()
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int o = 0, z = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                o++;
            else
                z++;
        }
        if (o == 0 || z == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << min(o, z) - 1 << endl;
        }
    }
    return 0;
}
