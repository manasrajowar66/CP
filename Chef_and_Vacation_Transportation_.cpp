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

signed main()
{
    tci()
    {
        int x, y, z;
        cin >> x >> y >> z;
        if ((x + y) < z)
        {
            cout << "PLANEBUS" << endl;
        }
        else if (z < (x + y))
        {
            cout << "TRAIN" << endl;
        }
        else
        {
            cout << "EQUAL" << endl;
        }
    }
    return 0;
}
