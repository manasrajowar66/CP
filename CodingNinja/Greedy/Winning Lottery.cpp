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
    tci()
    {
        int n, d;
        cin >> n >> d;
        int *arr = new int[d + 1];
        for (int i = d; i > 0; i--)
        {
            if (i != 1 && n - 9 == 0)
            {
                arr[i] = 8;
                n -= 8;
            }
            else if (i != 1 && n - 9 < 0 && n > 1)
            {
                arr[i] = n - 1;
                n = 1;
            }
            else if (i != 1 && n - 9 > 0)
            {
                arr[i] = 9;
                n -= 9;
            }
            else if (i != 1 && n - 9 < 0 && n == 1)
            {
                arr[i] = 0;
            }
            else if (i == 1)
            {
                arr[i] = n;
                n = 0;
            }
        }
        for (int i = 1; i <= d; i++)
        {
            cout << arr[i];
        }
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
