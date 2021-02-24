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

map<string, vector<vector<string>>> mpp;

auto countConstruct(string target, vector<string> str)
{
    if (mpp.find(target) != mpp.end())
        return mpp[target];
    if (target.length() == 0)
    {
        vector<vector<string>> v;
        v[0].push_back("-1");
        return v;
    }
    vector<vector<string>> all;
    for (auto s : str)
    {
        size_t p = target.find(s);
        if (p == 0)
        {
            string suffix = target.substr(s.length());
            vector<vector<string>> temp = countConstruct(suffix, str);
            if (temp.size() != 0)
            {
                if (temp[0][0] == "-1")
                {
                    temp.pop_back();
                }
                if (temp.size() == 0)
                {
                    temp[0].push_back(s);
                }
                else
                {
                    for (int i = 0; i < temp.size(); i++)
                    {
                        temp[i].push_back(s);
                    }
                }
                for (auto x : temp)
                {
                    all.push_back(x);
                }
            }
        }
    }
    mpp[target] = all;
    return mpp[target];
}

signed main()
{
    // int n;
    // string target;
    // vector<string> str;
    // cin >> n >> target;
    // for (int i = 0; i < n; i++)
    // {
    //     string s;
    //     cin >> s;
    //     str.push_back(s);
    // }
    // vector<vector<string>> all = countConstruct(target, str);
    // cout << all.size();
    // for (auto x : all)
    // {
    //     for (auto u : x)
    //     {
    //         cout << u << " ";
    //     }
    //     cout << endl;
    // }
    vector<vector<string>> v;
    v[0].push_back("av");
    v[0][1] = "2";
    cout << v[0].size();
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j];
        }
    }
    return 0;
}