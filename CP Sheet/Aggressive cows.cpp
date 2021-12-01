//https://www.spoj.com/problems/AGGRCOW/

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

bool is_possible(int *arr, int n, int c, int dist)
{
    int target = arr[0] + dist;
    for (int i = 1; i < n; i++)
    {
        if (target <= arr[i])
        {
            c--;
            target = arr[i] + dist;
        }
        if (c == 0)
        {
            return true;
        }
    }

    return false;
}

signed main()
{
    tci()
    {
        int n, c;
        cin >> n >> c;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int high = arr[n - 1];
        int low = arr[0];
        int ans = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (is_possible(arr, n, c - 1, mid))
            {
                ans = max(ans, mid);
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
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
