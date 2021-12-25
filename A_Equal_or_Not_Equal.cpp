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

string solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> arr(n);
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == 'E')
        {
            arr[i] = cnt;
        }
        else
        {
            cnt++;
            arr[i] = cnt;
        }
    }
    if (s[n - 1] == 'E')
    {
        arr[0] = arr[n - 1];
    }
    else
    {
        arr[0] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 'E')
        {
            arr[i + 1] = arr[i];
        }
        else if (s[i] == 'N' && arr[i] == arr[i + 1])
        {
            arr[i + 1]++;
        }
    }
    if (s[n - 1] == 'E')
    {
        arr[0] = arr[n - 1];
    }
    else if (s[n - 1] == 'N' && arr[n - 1] == arr[0])
    {
        arr[0]++;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 'E' && arr[i] != arr[i + 1])
            return "NO";
        else if (s[i] == 'N' && arr[i] == arr[i + 1])
            return "NO";
    }
    if (s[n - 1] == 'E' && arr[n - 1] != arr[0])
    {
        return "NO";
    }
    else if (s[n - 1] == 'N' && arr[n - 1] == arr[0])
    {
        return "NO";
    }
    return "YES";
}

signed main()
{
    tci()
    {
        cout << solve() << endl;
    }
    return 0;
}
