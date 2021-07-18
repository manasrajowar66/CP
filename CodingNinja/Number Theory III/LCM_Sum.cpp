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
int phi[100001];

void setSeive()
{
    for (int i = 1; i < 100001; i++)
        phi[i] = i;
    for (int i = 2; i <= 100000; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= 100000; j += i)
            {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
        }
    }
}

signed main()
{
    setSeive();
    tci()
    {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; (i * i) <= n; i++)
        {
            if (n % i == 0)
            {
                ans += (phi[i] * i);
                if ((n / i) != i)
                {
                    ans += (phi[n / i] * (n / i));
                }
            }
        }
        ans = ((ans + 1) * n) / 2;
        cout << ans << endl;
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
