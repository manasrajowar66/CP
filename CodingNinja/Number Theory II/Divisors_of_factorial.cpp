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
#define Max 50001
int power(int, int);
bool isPrime(int);

vector<int> seive()
{
    bool is_prime[Max];
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < Max; i++)
    {
        is_prime[i] = true;
    }

    for (int i = 2; i * i < Max; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < Max; j += i)
            {
                if (is_prime[j])
                    is_prime[j] = false;
            }
        }
    }

    vector<int> arr;
    for (int i = 2; i < Max; i++)
    {
        if (is_prime[i])
        {
            arr.push_back(i);
        }
    }
    return arr;
}

signed main()
{
    vector<int> arr = seive();
    tci()
    {
        int n;
        cin >> n;
        int ans = 1;
        for (int i = 0; arr[i] <= n; i++)
        {
            int count = 0;
            int k = arr[i];
            while ((n / k) != 0)
            {
                count = (count + (n / k)) % Mod;
                k = (k * arr[i]) % Mod;
            }
            ans = (ans * (count + 1) % Mod) % Mod;
        }
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
