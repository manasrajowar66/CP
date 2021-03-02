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

int power(int a, int n, int d)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res = ((res % d) * (a % d)) % d;
            n--;
        }
        else
        {
            a = ((a % d) * (a % d)) % d;
            n /= 2;
        }
    }
    return res;
}

int gcd(int a, int b, int n)
{
    if (a == b)
        return (power(a, n, mod) % mod + power(b, n, mod) % mod) % mod;
    int ans = 1;
    int B = a - b;
    for (int i = 1; i * i <= B; i++)
    {
        if (B % i == 0)
        {
            int temp = (power(a, n, i) + power(b, n, i)) % i;
            if (temp == 0)
                ans = max(ans, i);
            temp = (power(a, n, B / i) + power(b, n, B / i)) % (B / i);
            if (temp == 0)
                ans = max(ans, B / i);
        }
    }
    return ans % mod;
}

signed main()
{
    tci()
    {
        int a, b, n;
        cin >> a >> b >> n;
        cout << gcd(a, b, n) << endl;
    }
    return 0;
}
