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

signed main()
{
    tci()
    {
        string s;
        cin >> s;
        int startInd = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a')
            {
                startInd = i;
                break;
            }
        }
        if (startInd == -1)
        {
            cout << "NO" << endl;
        }
        else
        {
            bool fl = true;
            for (int i = startInd; i > 0; i--)
            {
                if (s[i] >= s[i - 1])
                {
                    fl = false;
                    break;
                }
            }
            if (fl)
            {
                for (int i = startInd; i < s.size() - 1; i++)
                {
                    if (s[i] >= s[i + 1])
                    {
                        fl = false;
                        break;
                    }
                }
                if (fl)
                {
                    sort(s.begin(), s.end());
                    for (int i = 0; i < s.size() - 1; i++)
                    {
                        if (s[i] + 1 != s[i + 1])
                        {
                            fl = false;
                            break;
                        }
                    }
                    if (fl)
                    {
                        cout << "YES" << endl;
                    }
                    else
                    {
                        cout << "NO" << endl;
                    }
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
            else
            {
                cout << "NO" << endl;
            }
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
