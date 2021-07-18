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

int solve(int n, int p)
{
    int ans = -1;
    for (int i = n + 1; i < p; i++)
    {
        ans = (ans * (power(i, p - 2, p) % p)) % p;
    }
    return (ans + p);
}

signed main()
{
    tci()
    {
        int n, p;
        cin >> n >> p;
        if (n >= p)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << solve(n, p) << endl;
        }
    }
    return 0;
}

// My Functions //

int power(int a, int n, int p)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res = (res % p * a % p) % p;
            n--;
        }
        else
        {
            a = (a % p * a % p) % p;
            n /= 2;
        }
    }
    return res % p;
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
