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

signed main()
{
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++)
    {
        int g00, g01, g02, g10, g11, g12, g20, g21, g22;
        cin >> g00 >> g01 >> g02 >> g10 >> g12 >> g20 >> g21 >> g22;
        map<int, int> hash;
        // int firstDiagonalDiff = abs(g00 - g22) / 2 + min(g00, g22);
        // int secondDiagonalDiff = abs(g02 - g20) / 2 + min(g02, g20);
        // int middleColumnDiff = abs(g01 - g21) / 2 + min(g01, g21);
        // int middleRowDiff = abs(g10 - g12) / 2 + min(g10, g12);
        // hash[firstDiagonalDiff]++;
        // hash[secondDiagonalDiff]++;
        // hash[middleColumnDiff]++;
        // hash[middleRowDiff]++;
        int ans = 0;

        if ((g00 + g22) % 2 == 0)
        {
            hash[(g00 + g22) / 2]++;
        }
        if ((g02 + g20) % 2 == 0)
        {
            hash[(g02 + g20) / 2]++;
        }
        if ((g01 + g21) % 2 == 0)
        {
            hash[(g01 + g21) / 2]++;
        }
        if ((g10 + g12) % 2 == 0)
        {
            hash[(g10 + g12) / 2]++;
        }

        for (auto u : hash)
        {
            ans = max(ans, u.second);
        }
        // cout << ans << endl;
        if ((g00 + g02) % 2 == 0 && ((g00 + g02) / 2) == g01)
        {
            ans++;
            // cout << "1 " << ans << endl;
        }
        if ((g02 + g22) % 2 == 0 && ((g02 + g22) / 2) == g12)
        {
            ans++;
            // cout << "2 " << ans << endl;
        }
        if ((g22 + g20) % 2 == 0 && ((g22 + g20) / 2) == g21)
        {
            ans++;
            // cout << "3 " << ans << endl;
        }
        if ((g00 + g20) % 2 == 0 && ((g00 + g20) / 2) == g10)
        {
            ans++;
            // cout << "4 " << ans << endl;
        }
        cout << "Case #" << test << ": " << ans << endl;
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
