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

void solve(int &start, int &end, string s)
{

    if (s.size() >= 2 && s[0] == '0' && s[s.size() - 1] == '0')
    {
        start = -1;
        end = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                end = i;
                if (start == -1)
                {
                    start = i;
                }
            }
            else if (end - start >= 1)
            {
                break;
            }
        }
    }
    else if (s.size() >= 2 && s[0] == '1' && s[s.size() - 1] == '1')
    {
        start = -1;
        end = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                end = i;
                if (start == -1)
                {
                    start = i;
                }
            }
            else if (end - start >= 1)
            {
                break;
            }
        }
    }
    else
    {
        start = 0;
        end = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[start] == s[i])
            {
                end = i;
            }
            else if (start == end && s[start] != s[i])
            {
                start = i;
                end = i;
            }
            else if ((end - start) > 0 && s[start] != s[i])
            {
                break;
            }
        }
    }
}

signed main()
{
    tci()
    {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        if (b >= 0)
        {
            cout << (a + b) * n << endl;
        }
        else
        {
            int start, end;
            int ans = 0;
            while (s.size() != 0)
            {
                solve(start, end, s);
                // cout << start << " " << end << endl;
                if (start == -1 && end == -1)
                {
                    ans += (a)*s.size() + b;
                    s.erase(0);
                    // cout << s << endl;
                }
                else if (start == end)
                {
                    ans += (a + b) * s.size();
                    s.erase(0);
                    // cout << s << endl;
                }
                else
                {
                    ans += a * (end - start + 1) + b;
                    s.erase(start, end - start + 1);
                    // cout << s << endl;
                }
            }
            cout << ans << endl;
        }
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
