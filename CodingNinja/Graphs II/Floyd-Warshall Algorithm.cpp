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
#define Max 1000000000
int power(int, int);
bool isPrime(int);

signed main()
{
    tci()
    {
        int v, e;
        cin >> v >> e;
        int **dist = new int *[v + 1];
        for (int i = 0; i <= v; i++)
        {
            dist[i] = new int[v + 1];
            for (int j = 0; j <= v; j++)
            {
                if (i == j)
                {
                    dist[i][j] = 0;
                }
                else
                {
                    dist[i][j] = INT_MAX;
                }
            }
        }
        while (e--)
        {
            int a, b, d;
            cin >> a >> b >> d;
            if (dist[a][b] > d)
            {
                dist[a][b] = d;
                dist[b][a] = d;
            }
        }

        for (int k = 1; k <= v; k++)
        {
            for (int i = 1; i <= v; i++)
            {
                for (int j = 1; j <= v; j++)
                {
                    if (i != j)
                    {
                        if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                        {
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }
        }
        int q;
        cin >> q;
        while (q--)
        {
            int a, b;
            cin >> a >> b;
            if (dist[a][b] == INT_MAX)
            {
                cout << Max << endl;
            }
            else
            {
                cout << dist[a][b] << endl;
            }
        }
        for (int i = 0; i <= v; i++)
        {
            delete[] dist[i];
        }
        delete[] dist;
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
