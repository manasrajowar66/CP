#include <bits/stdc++.h>
#include <unordered_map>
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
int memo[109][100009];
int a[100009], b[100009];
int knapsack(int val, int ind, int n)
{
    if (memo[ind][val] != -1)
        return memo[ind][val];
    if (ind == n)
        return (val == 0) ? 0 : INT_MAX;

    int res = knapsack(val, ind + 1, n);
    if (val - b[ind] >= 0)
        res = min(res, a[ind] + knapsack(val - b[ind], ind + 1, n));
    return memo[ind][val] = res;
}

int solve(int max_val, int W, int n)
{
    for (int i = max_val; i >= 0; i--)
    {
        if (knapsack(i, 0, n) <= W)
            return i;
    }
    return 0;
}

signed main()
{
    memset(memo, -1, sizeof(memo));
    int n, W, max_val = 0;
    cin >> n >> W;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        max_val += b[i];
    }
    cout << solve(max_val, W, n);
    return 0;
}
