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

int solve1(string s, int n)
{
    int team_1 = 0;
    int team_2 = 0;
    int kicks = 0;
    for (int i = 0; i < n; i++)
    {
        if ((i + 1) & 1)
        {
            if (team_1 > ((10 - i) / 2 + team_2) || ((10 - i) / 2 + team_1) < team_2)
            {
                break;
            }
            else
            {
                kicks++;
            }
            if (s[i] == '1' || s[i] == '?')
            {
                team_1++;
            }
            cout << kicks << " " << team_1 << " " << team_2 << endl;
        }
        else
        {
            if ((team_2 > ((10 - i) / 2 + team_1)) || (((10 - i + 1) + team_2) < team_1))
            {
                break;
            }
            else
            {
                kicks++;
            }
            if (s[i] == '1')
            {
                team_2++;
            }
            cout << kicks << " " << team_1 << " " << team_2 << endl;
        }
    }
    return kicks;
}

int solve2(string s, int n)
{
    int team_1 = 0;
    int team_2 = 0;
    int kicks = 0;
    for (int i = 0; i < n; i++)
    {
        if ((i + 1) & 1)
        {
            if ((team_2 > ((10 - i) / 2 + team_1)) || (((10 - i + 1) + team_2) < team_1))
            {
                break;
            }
            else
            {
                kicks++;
            }
            if (s[i] == '1')
            {
                team_1++;
            }
            cout << kicks << " " << i << endl;
        }
        else
        {
            if (team_2 > ((10 - i) / 2 + team_1) || ((10 - i + 1) + team_2) < team_1)
            {
                break;
            }
            else
            {
                kicks++;
            }
            if (s[i] == '1' || s[i] == '?')
            {
                team_2++;
            }
            cout << kicks << " " << i << endl;
        }
    }
    return kicks;
}

signed main()
{
    tci()
    {
        string s;
        cin >> s;
        cout << "Option1 ..." << endl;
        int option1 = solve1(s, 10);
        cout << "Option2 ..." << endl;
        int option2 = solve2(s, 10);
        // cout << min(option1, option2) << endl;
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
