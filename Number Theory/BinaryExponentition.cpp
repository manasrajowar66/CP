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
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define Mod 13

//O(log(n))
int power(int base, int n)
{
    if (base == 1)
        return 1;
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
        {
            ans = ans * base;
            n = n - 1;
        }
        else
        {
            base *= base;
            n = n / 2;
        }
    }
    return ans;
}

//Modulo Exponentiation

int modPower(int base, int n)
{
    if (base == 1)
        return 1;
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
        {
            ans = (ans * base) % Mod;
            n = n - 1;
        }
        else
        {
            base = (base * base) % Mod;
            n = n / 2;
        }
    }
    return ans;
}

signed main()
{
    int base, n;
    cin >> base >> n;
    cout << power(base, n);
    return 0;
}
