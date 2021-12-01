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

int solve(string s, int len, int i, int *counter)
{
    int ans = 0, k = 1;
    while (true)
    {
        int end = i + k + (k * k);
        if (end > len)
        {
            break;
        }
        int cnt1 = counter[end] - counter[i];
        if (cnt1 == k)
        {
            ans++;
        }
        k++;
    }
    // cout << k << " " << ans << " " << counter[k] << endl;
    return ans;
}

signed main()
{
    tci()
    {
        string s;
        cin >> s;
        int len = s.length();
        int ans = 0;
        int *counter = new int[len + 1]();
        for (int i = 1; i <= len; i++)
        {
            counter[i] = counter[i - 1] + (s[i - 1] - '0');
        }
        for (int i = 0; i < len; i++)
        {
            ans += solve(s, len, i, counter);
        }
        cout << ans << endl;
        delete[] counter;
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
