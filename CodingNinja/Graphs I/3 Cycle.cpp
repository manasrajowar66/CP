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

bool check(int **edges, int i, int j)
{
    return edges[i][j] == 1;
}
int solve(int **edges, int v)
{
    int count = 0;
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (i != j && check(edges, i, j))
            {
                for (int k = 1; k <= v; k++)
                {
                    if (k != i && k != j && check(edges, j, k))
                    {
                        if (check(edges, k, i))
                        {
                            count++;
                        }
                    }
                }
            }
        }
    }
    return (count / 6);
}

signed main()
{
    int v, e;
    cin >> v >> e;
    int **edges = new int *[v + 1];
    int *a = new int[e]();
    int *b = new int[e]();
    for (int i = 0; i <= v; i++)
    {
        edges[i] = new int[v + 1]();
    }
    for (int i = 0; i < e; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < e; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < e; i++)
    {
        edges[a[i]][b[i]] = 1;
        edges[b[i]][a[i]] = 1;
    }
    cout << solve(edges, v) << endl;
    for (int i = 0; i <= v; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    delete[] a;
    delete[] b;
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
