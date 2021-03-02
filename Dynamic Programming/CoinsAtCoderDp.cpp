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
double Harr[3009];
double memo[3009][3009];
int n;
double coins(int ind, int heads, int tails)
{
    if (memo[heads][ind] != -1.0)
        return memo[heads][ind];
    if (ind == n)
    {
        if (heads >= tails)
        {
            return 1.0;
        }
        else
        {
            return 0.0;
        }
    }
    double res1 = 0.0;
    res1 += Harr[ind] * coins(ind + 1, heads + 1, tails);
    double res2 = 0.0;
    res2 += (1.0 - Harr[ind]) * coins(ind + 1, heads, tails + 1);
    return memo[heads][ind] = res1 + res2;
}

signed main()
{
    memset(memo, -1.0, sizeof(memo));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double x;
        cin >> x;
        Harr[i] = x;
    }
    cout << coins(0, 0, 0);

    return 0;
}
