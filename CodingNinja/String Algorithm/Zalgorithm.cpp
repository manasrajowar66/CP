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

void Zalgorithm(string s, int n, int *Z)
{
    int l = 0, r = 0;
    Z[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > r)
        {
            r = i;
            l = i;
            while (r < n && s[r - l] == s[r])
            {
                r++;
            }
            Z[i] = r - l;
            r--;
        }
        else
        {
            int k = i - l;
            if (Z[k] <= r - i)
            {
                Z[i] = Z[k];
            }
            else
            {
                l = i;
                while (r < n && s[r - l] == s[r])
                {
                    r++;
                }
                Z[i] = r - l;
                r--;
            }
        }
    }
}

int patternSearch(string text, string patt, int k)
{
    string s = patt + "$" + text;
    int len = s.length();
    int *Z = new int[len];
    Zalgorithm(s, len, Z);
    int count = 0;
    int pattLen = patt.length();
    for (int i = 0; i < len; i++)
    {
        if ((Z[i] >= k) && (i - pattLen - 1) >= 0)
        {
            count++;
        }
    }
    if (count == 0)
    {
        return -1;
    }
    return count;
}

signed main()
{
    int n, m, k;
    cin >> n >> m >> k;
    string text, patt;
    cin >> text >> patt;
    cout << patternSearch(text, patt, k) << endl;
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
