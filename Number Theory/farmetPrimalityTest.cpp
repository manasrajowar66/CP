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
bool isPrime(int, int);

int mulmod(int a, int b, int mod)
{
    int x = 0, y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2LL) % mod;
        b /= 2;
    }
    return x % mod;
}

signed main()
{
    tci()
    {
        int n;
        cin >> n;
        if (isPrime(n, 5))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

// My Functions //

int power(int a, int n, int mod)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res = mulmod(res, a, mod);
            n--;
        }
        else
        {
            a = mulmod(a, a, mod);
            n /= 2;
        }
    }
    return res;
}

bool isPrime(int n, int itration)
{
    if (n <= 4)
        return n == 2 || n == 3;
    for (int i = 1; i <= itration; i++)
    {
        int a = 2 + rand() % (n - 3);
        int res = power(a, n - 1, n);
        if (res != 1)
            return false;
    }
    return true;
}
