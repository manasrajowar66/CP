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
#define endl "\n"
#define Mod 1000000007
int power(int, int);
bool isPrime(int);
bool is_prime[1000001];
vi primes;

void setSeive()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < 1000001; i++)
    {
        is_prime[i] = true;
    }

    for (int i = 2; i * i < 1000001; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < 1000001; j += i)
            {
                if (is_prime[j])
                    is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i < 1000001; i++)
    {
        if (is_prime[i])
            primes.push_back(i);
    }
}

int segmentedSeive(int l, int r, int k)
{
    // if (l == 1)
    //     l++;
    int maxN = r - l + 1;
    int *arr = new int[maxN];
    int *arr2 = new int[maxN];
    vector<int> vec;
    for (int i = 0; i < maxN; i++)
    {
        arr[i] = l + i;
        arr2[i] = l + i;
    }
    // for (int i = 0; i < maxN; i++)
    // {
    //     cout << arr2[i] << " ";
    // }
    // cout << endl;
    for (auto p : primes)
    {
        if (p * p <= r)
        {
            int i = (l / p) * p;
            if (i < l)
                i += p;
            for (; i <= r; i += p)
            {
                arr[i - l] /= p;
                arr[i - l] *= (p - 1);
                while ((arr2[i - l] % p) == 0)
                {
                    arr2[i - l] /= p;
                }
            }
        }
    }
    for (int i = 0; i < maxN; i++)
    {
        if (arr2[i] != 1)
        {
            arr[i] = arr[i] / arr2[i];
            arr[i] = arr[i] * (arr2[i] - 1);
        }
    }
    int count = 0;
    for (int i = 0; i < maxN; i++)
    {
        if (arr[i] % k == 0)
        {
            count++;
        }
    }
    delete[] arr;
    delete[] arr2;
    return count;
}
signed main()
{
    setSeive();
    tci()
    {
        int l, r, k;
        cin >> l >> r >> k;
        std::cout << std::fixed;
        std::cout << std::setprecision(6);
        cout << (double)segmentedSeive(l, r, k) / (double)(r - l + 1) << endl;
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
