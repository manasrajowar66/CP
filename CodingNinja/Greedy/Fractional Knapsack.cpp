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
#define ff first
#define ss second
int power(int, int);
bool isPrime(int);

bool comp(pair<double, double> p1, pair<double, double> p2)
{
    if (p1.ff >= p2.ff)
    {
        return true;
    }
    return false;
}

signed main()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    int n, W;
    cin >> n >> W;
    int *value = new int[n];
    int *weight = new int[n];
    pair<double, int> *unit_capacity = new pair<double, int>[n];
    for (int i = 0; i < n; i++)
    {
        cin >> value[i] >> weight[i];
        unit_capacity[i].ff = ((double)value[i] / (double)weight[i]);
        unit_capacity[i].ss = i;
    }
    sort(unit_capacity, unit_capacity + n, comp);
    double ans = 0;
    for (int i = 0; i < n && W >= 0; i++)
    {
        if (weight[unit_capacity[i].ss] <= W)
        {
            ans += (double)value[unit_capacity[i].ss];
            W -= weight[unit_capacity[i].ss];
        }
        else
        {
            ans += (double)(unit_capacity[i].ff * (double)W);
            W = 0;
        }
    }
    cout << ans << endl;
    delete[] value;
    delete[] weight;
    delete[] unit_capacity;
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
