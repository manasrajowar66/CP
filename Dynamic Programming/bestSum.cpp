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
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
map<int, vector<int>> mpp;
auto bestSum(int sum, int a[], int n)
{
    if (mpp.find(sum) != mpp.end())
        return mpp[sum];
    if (sum == 0)
    {
        vec v = {0};
        return v;
    }
    if (sum < 0)
    {
        vec v = {-1};
        return v;
    }
    vec shortCombi = {-1};
    for (int i = 0; i < n; i++)
    {
        int remainder = sum - a[i];
        vec remainderCombi = bestSum(remainder, a, n);
        if (remainderCombi[0] != -1)
        {
            if (remainderCombi[0] == 0)
                remainderCombi.pop_back();
            vec combi = remainderCombi;
            combi.push_back(a[i]);
            if (shortCombi[0] == -1 || shortCombi.size() > combi.size())
                shortCombi = combi;
        }
    }

    mpp[sum] = shortCombi;
    return mpp[sum];
}

signed main()
{
    int sum, n;
    cin >> n >> sum;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vec vi = bestSum(sum, a, n);
    if (vi[0] == -1)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        for (auto x : vi)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
