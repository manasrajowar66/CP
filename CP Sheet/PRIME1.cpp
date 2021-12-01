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
int is_prime[1000001];
vector<int> primes;

void setSeive()
{
    for (int i = 2; i < 1000001; i++)
    {
        is_prime[i] = 1;
    }

    for (int i = 2; i * i < 1000001; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < 1000001; j += i)
            {
                if (is_prime[j])
                {
                    is_prime[j] = 0;
                }
            }
        }
    }

    for (int i = 2; i < 1000001; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }
}

void segmentedSeive(int l, int r)
{
    if (l == 1)
    {
        l++;
    }

    int maxN = r - l + 1;
    int *arr = new int[maxN];
    memset(arr, 1, sizeof(arr));

    for (auto p : primes)
    {
        if (p * p <= r)
        {
            int i = (l / p) * p;
            if (i < l)
            {
                i += p;
            }
            for (; i <= r; i += p)
            {
                if (i != p)
                {
                    arr[i - l] = 0;
                }
            }
        }
    }
    for (int i = 0; i < maxN; i++)
    {
        if (arr[i])
        {
            cout << i + l << endl;
        }
    }
    delete[] arr;
}

signed main()
{
    setSeive();
    tci()
    {
        int l, r;
        cin >> l >> r;
        segmentedSeive(l, r);
        cout << endl;
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
