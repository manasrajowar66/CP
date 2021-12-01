//https://codeforces.com/contest/5/problem/C

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

pair<int, int> solve(string str)
{
    int n = str.length();
    int no_of_strings = 0;

    stack<int> stk;
    stk.push(-1);

    int result = 0;

    for (int i = 0; i < n; i++)
    {

        if (str[i] == '(')
            stk.push(i);

        else
        {

            if (!stk.empty())
            {
                stk.pop();
            }

            if (!stk.empty())
                result = max(result, i - stk.top());
            else
            {
                stk.push(i);
                no_of_strings++;
            }
        }
    }

    if (result == 0)
        return {0, 1};
    return {result, no_of_strings};
}

signed main()
{
    string s;
    cin >> s;
    pair<int, int> ans = solve(s);
    cout << ans.first << " " << ans.second;
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
