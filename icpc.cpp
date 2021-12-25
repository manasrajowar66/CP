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

class Products
{
public:
    float a, x, y;
};
void profitLoss(int n, Products p[])
{
    double cost = 0, seling = 0;
    for (int i = 0; i < n; i++)
    {
        cost += p[i].a;
        double temp = p[i].a + p[i].a * (float)(p[i].x / (float)100);
        temp = temp - temp * (float)(p[i].y / (float)100);
        seling += temp;
    }
    if (cost > seling)
    {
        cout << "Loss"
             << " " << (int)(cost - seling);
    }
    else
    {
        cout << "Profit"
             << " " << (int)(seling - cost);
    }
}
signed main()
{
    int n;
    float a, x, y;
    cin >> n;
    Products p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a >> x >> y;
        p[i].a = a;
        p[i].x = x;
        p[i].y = y;
    }
    profitLoss(n, p);
    return 0;
}
