// Eular totirnt function

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
int phi[1000001];

void setSeive()
{
    for (int i = 1; i < 1000001; i++)
        phi[i] = i;
    for (int i = 2; i <= 1000000; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= 1000000; j += i)
            {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
        }
    }
}

//O(sqrt(n))
int findCoprimes(int n)
{
    int ans = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans /= i;
            ans *= (i - 1);
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n > 1)
    {
        ans /= n;
        ans *= (n - 1);
    }
    return ans;
}

// O(Nlog(log(N)))

int findCoprimes2(int n)
{
    return phi[n];
}

signed main()
{
    setSeive();
    tci()
    {
        int n;
        cin >> n;

        cout << findCoprimes2(n) << endl;
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
