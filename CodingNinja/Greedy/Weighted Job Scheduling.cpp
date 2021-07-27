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
#define ff first
#define ss second
int power(int, int);
bool isPrime(int);

bool comp(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2)
{
    if (p1.ss.ss < p2.ss.ss)
    {
        return true;
    }
    // else if (p1.ss.ss == p2.ss.ss)
    // {
    //     if (p1.ss.ff <= p2.ss.ff)
    //     {
    //         return true;
    //     }
    // }
    return false;
}

int search_ind(pair<int, pair<int, int>> *arr, int start, int end, int item)
{
    int ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid].ss.ss <= item)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

signed main()
{
    int n;
    cin >> n;
    pair<int, pair<int, int>> *arr = new pair<int, pair<int, int>>[n];
    int *dp = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].ss.ff;
        cin >> arr[i].ss.ss;
        cin >> arr[i].ff;
    }
    sort(arr, arr + n, comp);
    // int  last_selected_ind = 0;
    dp[0] = arr[0].ff;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i].ff << " " << arr[i].ss.ff << " " << arr[i].ss.ss << endl;
    // }
    // cout << "Ind Printing..." << endl;
    for (int i = 1; i < n; i++)
    {
        int ind = search_ind(arr, 0, i - 1, arr[i].ss.ff);
        if (ind != -1)
        {
            dp[i] = max(arr[i].ff + dp[ind], dp[i - 1]);
        }
        else
        {
            dp[i] = max(arr[i].ff, dp[i - 1]);
        }
    }
    cout << dp[n - 1] << endl;
    delete[] arr;
    delete[] dp;
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
