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
#define mod 1000000007
char square[1002][1002];
int memo[1002][1002];
int h, w;
int gridTraveller(int row, int col)
{
    if (memo[row][col] != -1)
        return memo[row][col];
    if (row == h - 1 && col == w - 1)
        return 1;
    if (row >= h || col >= w)
        return 0;
    int res = 0;
    if (col + 1 < w && square[row][col + 1] != '#')
    {
        res += gridTraveller(row, col + 1) % mod;
    }
    if (row + 1 < h && square[row + 1][col] != '#')
    {
        res += gridTraveller(row + 1, col) % mod;
    }
    return memo[row][col] = res % mod;
}

signed main()
{
    memset(memo, -1, sizeof(memo));
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            cin >> square[i][j];
    }
    cout << gridTraveller(0, 0);
    return 0;
}
