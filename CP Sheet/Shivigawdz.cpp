//https://www.codechef.com/problems/SHIVIGOD

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

double solve(int *arr, int n, int k)
{
    double ans = DBL_MIN, sum = 0;
    int i = 0;
    for (; i < k; i++)
    {
        sum += arr[i];
    }
    ans = max(ans, sum);
    for (; i < n; i++)
    {
        sum -= arr[i - k];
        sum += arr[i];
        ans = max(ans, sum);
    }
    // cout << ans << " " << k << endl;
    ans = ans / k;
    return ans;
}

signed main()
{
    tci()
    {
        int n, a, b;
        cin >> n >> b >> a;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << fixed << setprecision(6);
        double ans = DBL_MIN;
        for (int i = a; i <= b; i++)
        {
            ans = max(ans, solve(arr, n, i));
        }
        cout << ans << endl;
        delete[] arr;
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
