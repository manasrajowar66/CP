//https://www.codechef.com/problems/THESAV

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

string solve(string s)
{
    int food_pakages = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            if (food_pakages == 0)
            {
                return "NO";
            }
            food_pakages--;
        }
        if (s[i] == '*')
        {
            food_pakages += 2;
        }
    }
    return "YES";
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
