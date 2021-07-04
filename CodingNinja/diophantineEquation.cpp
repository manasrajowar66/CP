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

int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

bool solve(int a, int b, int c, int &x, int &y)
{
    int x0, y0;
    int g = gcd(abs(a), abs(b), x0, y0);
    if (c % g)
    {
        return false;
    }

    x = x0 * (c / g);
    y = y0 * (c / g);

    x = a < 0 ? -x : x;
    y = b < 0 ? -y : y;
    return true;
}

signed main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int x, y;
    if (solve(a, b, c, x, y) == false)
    {
        cout << "Solution Not Exist";
    }
    else
    {
        cout << "X: " << x << endl
             << "Y: " << y;
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
