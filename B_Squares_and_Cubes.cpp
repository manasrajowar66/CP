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

int solve(int n)
{
    unordered_map<int, int> hash;
    int ans = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (hash.find(i * i) == hash.end())
        {
            hash[i * i] = 1;
            ans++;
        }
    }
    for (int i = 1; i * i * i <= n; i++)
    {
        if (hash.find(i * i * i) == hash.end())
        {
            hash[i * i * i] = 1;
            ans++;
        }
    }
    return ans;
}

signed main()
{
    tci()
    {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
