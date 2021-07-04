#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lli long long int
#define ll long long
#define vi vector<int>
#define for0() for (int i = 0; i < n; i++)
#define for1() for (int i = 1; i <= n; i++)
#define backloop() for (int i = n - 1; i >= 0; i--)
#define tci() \
    int t;    \
    cin >> t; \
    while (t--)
#define pb push_back
#define endl "\n"
#define Mod 1000000007
int power(int, int);
bool isPrime(int);

signed main()
{
    tci()
    {
        int n, e, h, a, b, c;
        cin >> n >> e >> h >> a >> b >> c;
        vi res, temp;
        for (int i = 0; i <= n + 1; i++)
            temp.pb(i);
        for (int i = 0; i <= n; i++)
        {
            int ind1 = lower_bound(temp.begin(), temp.end(), (2 * n - e - 2 * i)) - temp.begin();
            int ind2 = upper_bound(temp.begin(), temp.end(), (h - 3 * i)) - temp.begin() - 1;

            if ((ind2 < ind1 || ind1 == n + 1) || (ind2 == n + 1 && ind2 + 3 * i > h))
                continue;

            int k;
            if (c > a)
                k = ind1 < (n - i) ? ind1 : (n - i);
            else
                k = ind2 < (n - i) ? ind2 : (n - i);

            int x = n - k - i;
            if (k + 2 * i >= 2 * n - e && k + 3 * i <= h)
            {
                res.pb(a * x + b * i + c * k);
            }
        }
        if (res.size() == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            auto mini_price = min_element(res.begin(), res.end());
            cout << *mini_price << endl;
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
