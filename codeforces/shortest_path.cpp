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
int x2, y2, f1, f2;
int dp[1001][1001];

int shortest_path(int x1, int y1)
{
    int res = INT_MAX;
    if (x1 == x2 && y1 == y2)
    {
        return 1;
    }
    if (x1 == f1 && y1 == f2)
    {
        return INT_MAX;
    }
    if (x1 > 1001 && y1 > 1001)
    {
        return INT_MAX;
    }
    if (dp[x1][y1] != -1)
    {
        return dp[x1][y1];
    }
    if (y1 < 1001)
    {
        res = min(res, shortest_path(x1, y1 + 1));
    }
    if (x1 < 1001)
    {
        res = min(res, shortest_path(x1 + 1, y1));
    }
    if (y1 > 1)
    {
        res = min(res, shortest_path(x1, y1 - 1));
    }
    if (x1 > 1)
    {
        res = min(res, shortest_path(x1 - 1, y1));
    }
    dp[x1][y1] = 1 + res;
    return dp[x1][y1];
}

signed main()
{
    tci()
    {
        int x1, y1;
        cin >> x1 >> y1 >> x2 >> y2 >> f1 >> f2;
        memset(dp, -1, sizeof(dp));
        cout << shortest_path(x1, y1) << endl;
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
