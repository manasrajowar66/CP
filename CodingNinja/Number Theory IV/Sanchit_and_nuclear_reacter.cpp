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
int power(int, int, int);
bool isPrime(int);

int solve(int n, int m)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans % m * i % m) % m;
    }
    return (ans) % m;
}

signed main()
{
    tci()
    {
        int n, m;
        cin >> n >> m;
        if (n >= m)
        {
            int round = n / m;
            cout << ((power(m - 1, round, m) % m) * solve(n % m, m)) % m << endl;
        }
        else
        {
            cout << solve(n, m) << endl;
        }
    }
    return 0;
}

// My Functions //

int power(int a, int n, int m)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res = (res % m * a % m) % m;
            n--;
        }
        else
        {
            a = (a % m * a % m) % m;
            n /= 2;
        }
    }
    return res % m;
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
