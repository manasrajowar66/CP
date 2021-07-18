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

int convertToDecimal(string s, int m)
{
    int ans = 0;
    int len = s.size();
    for (int i = len - 1; i >= 0; i--)
    {
        ans = (ans + (((s[i] - '0') * power(3, len - i - 1, m)) % m)) % m;
    }
    return ans;
}

signed main()
{
    tci()
    {
        int a, m;
        string b;
        cin >> a >> b >> m;
        int B_Decimal = convertToDecimal(b, m - 1);
        // cout << B_Decimal << endl;
        cout << power(a, B_Decimal, m) << endl;
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
