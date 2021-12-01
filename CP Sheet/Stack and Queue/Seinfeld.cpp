//https://www.spoj.com/problems/ANARC09A/

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
    int operations = 0;
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                st.push('{');
                operations++;
            }
            else
            {
                if (st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    operations++;
                    st.pop();
                }
            }
        }
    }
    if (st.size() > 0)
    {
        operations += st.size() / 2;
    }
    return operations;
}

signed main()
{
    int test = 1;
    while (1)
    {
        string s;
        cin >> s;
        if (s[0] == '-')
        {
            break;
        }
        cout << test++ << ". " << solve(s) << endl;
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
