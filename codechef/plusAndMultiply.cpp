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

// int gcd(int a, int b, int &x, int &y)
// {
//     if (b == 0)
//     {
//         x = 1;
//         y = 0;
//         return a;
//     }
//     int x1, y1;
//     int g = gcd(b, a % b, x1, y1);
//     x = y1;
//     y = x1 - y1 * (a / b);
//     return g;
// }

bool solve(int a, int b, int c)
{
    bool flag = false;
    int curr = 1;
    while (curr <= c)
    {
        if ((c - curr) % b == 0)
        {
            flag = true;
            break;
        }
        curr *= a;
        if (a == 1)
        {
            break;
        }
    }
    return flag;
}

signed main()
{
    tci()
    {
        int a, b, c;
        cin >> c >> a >> b;
        if (solve(a, b, c) == false)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
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
