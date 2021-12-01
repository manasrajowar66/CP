//https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/maximum-occurrence-9/

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
    string s;
    map<char, int> hash;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
    {
        hash[s[i]]++;
    }
    char ans;
    int count = INT_MIN;
    for (auto v : hash)
    {
        if (count < v.second)
        {
            ans = v.first;
            count = v.second;
        }
        else if (count == v.second)
        {
            if (ans > v.first)
            {
                ans = v.first;
            }
        }
    }
    if (ans == ' ')
    {
        cout << " "
             << " " << count;
    }
    else
    {
        cout << ans << " " << count;
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
