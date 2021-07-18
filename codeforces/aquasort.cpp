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
#define ss second
#define ff first
int power(int, int);
bool isPrime(int);

signed main()
{
    tci()
    {
        int n;
        cin >> n;
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.push_back({x, i});
        }
        sort(arr.begin(), arr.end());
        int inversion = 0;
        bool fl = true;
        for (int i = 0; i < n; i++)
        {
            if (abs(arr[i].ss - i) % 2)
            {
                fl = false;
                break;
            }
            inversion += abs(arr[i].ss - i);
        }
        if (fl == false)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
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
