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

int solve(string s)
{
    int n = s.length();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        //For Odd length
        int l = i, r = i;
        string temp;
        while (l >= 0 && r < n && s[r] == s[l])
        {
            // cout << l << " odd " << r << " " << s.substr(l, r) << endl;
            if (r == l)
            {
                temp += s[r];
            }
            else
            {
                temp = s[l] + temp + s[r];
            }
            l--;
            r++;
            count++;
        }
        // if (temp.size() != 0)
        // {
        //     count++;
        // }

        //For Even Length
        l = i, r = i + 1;
        temp = "";
        while (l >= 0 && r < n && s[r] == s[l])
        {
            // cout << l << " even " << r << " " << s.substr(l, r) << endl;

            temp = s[l] + temp + s[r];

            l--;
            r++;
            count++;
        }
        // if (temp.size() != 0)
        // {
        //     count++;
        // }
    }
    return count;
}

signed main()
{
    tci()
    {
        string s;
        cin >> s;
        cout << solve(s) << endl;
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
