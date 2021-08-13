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

int *LPS(string p)
{
    int len = p.length();
    int *lps = new int[len + 1];
    lps[0] = 0;
    int i = 1, j = 0;
    while (i < len)
    {
        if (p[i] == p[j])
        {
            lps[i++] = j + 1;
            j++;
        }
        else
        {
            if (j == 0)
            {
                lps[i++] = 0;
            }
            else
            {
                j = lps[j - 1];
            }
        }
    }
    return lps;
}

bool isFound(string s, string p)
{
    int lenText = s.length();
    int lenPat = p.length();
    if (lenPat > lenText)
    {
        return false;
    }
    int *lps = LPS(p);
    int i = 0, j = 0;
    while (i < lenText && j < lenPat)
    {
        if (s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
    }
    delete[] lps;
    if (j == lenPat)
    {
        return true;
    }
    return false;
}

signed main()
{
    tci()
    {
        string s, p;
        cin >> p >> s;
        if (isFound(s, p))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
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
