#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lli long long int
#define ll long long
#define vec vector<int>
#define for0() for (int i = 0; i < n; i++)
#define for1() for (int i = 1; i <= n; i++)
#define backloop() for (int i = n - 1; i >= 0; i--)
#define ff first
#define ss second
#define tci() \
    int t;    \
    cin >> t; \
    while (t--)
#define endl "\n"
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

map<string, bool> mpp;

bool canConstruct(string target, vector<string> str)
{
    if (mpp.find(target) != mpp.end())
        return mpp[target];
    if (target.length() == 0)
        return true;

    for (auto s : str)
    {
        size_t p = target.find(s);
        if (p == 0)
        {
            string suffix = target.substr(s.length());
            if (canConstruct(suffix, str))
            {
                mpp[target] = true;
                return true;
            }
        }
    }
    mpp[target] = false;
    return false;
}

signed main()
{
    int n;
    string target;
    vector<string> str;
    cin >> n >> target;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        str.push_back(s);
    }
    if (canConstruct(target, str))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
