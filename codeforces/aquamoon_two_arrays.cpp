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
#define ss second
#define ff first

signed main()
{
    tci()
    {
        int n;
        cin >> n;
        vector<int> a;
        vector<int> b;
        vector<pair<int, int>> inc;
        vector<pair<int, int>> dec;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            b.push_back(x);
        }
        int incVal = 0, decVal = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i])
            {
                decVal += a[i] - b[i];
                dec.push_back({i + 1, a[i] - b[i]});
            }
            else if (a[i] < b[i])
            {
                incVal += b[i] - a[i];
                inc.push_back({i + 1, b[i] - a[i]});
            }
        }
        // cout << inc.size() << " " << dec.size() << endl;
        if (incVal != decVal)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << incVal << endl;
            reverse(inc.begin(), inc.end());
            reverse(dec.begin(), dec.end());
            pair<int, int> incEle = {0, 0};
            pair<int, int> decEle = {0, 0};
            while ((inc.size() != 0 && dec.size() != 0) || incEle.ss != 0 || decEle.ss != 0)
            {
                if (incEle.ss == 0)
                {
                    incEle = inc.back();
                    inc.pop_back();
                }
                if (decEle.ss == 0)
                {
                    decEle = dec.back();
                    dec.pop_back();
                }
                int loop = min(incEle.ss, decEle.ss);
                // cout << loop << endl;
                int diff = loop;
                for (int i = 1; i <= loop; i++)
                {
                    cout << decEle.ff << " " << incEle.ff << endl;
                }
                incEle.ss -= diff;
                decEle.ss -= diff;
                // cout << "yes" << endl;
            }
        }
    }
    return 0;
}
