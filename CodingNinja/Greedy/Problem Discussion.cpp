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
        int n, k;
        cin >> n >> k;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n);
        int maxi = arr[n - 1] - k, mini = arr[0] + k;
        if (mini > maxi)
        {
            swap(mini, maxi);
        }

        for (int i = 1; i < n - 1; i++)
        {
            int subt = arr[i] - k;
            int add = arr[i] + k;
            if (subt >= mini || add <= maxi)
            {
                continue;
            }
            else
            {
                if (maxi - subt <= add - mini)
                {
                    mini = subt;
                }
                else
                {
                    maxi = add;
                }
            }
        }

        cout << min(maxi - mini, arr[n - 1] - arr[0]) << endl;

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
