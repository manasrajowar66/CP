//https://atcoder.jp/contests/dp/tasks/dp_g

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

void dfs(vector<int> *edges, int *visited, int sv, int *depth)
{
    visited[sv] = 1;
    int maxi = 0;
    for (int i = 0; i < edges[sv].size(); i++)
    {
        int next = edges[sv][i];
        if (!visited[next])
        {
            dfs(edges, visited, next, depth);
        }
        maxi = max(maxi, depth[next]);
    }
    depth[sv] = maxi + 1;
}

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> *edges = new vector<int>[n];
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        edges[x - 1].push_back(y - 1);
    }
    int *visited = new int[n]();
    int *depth = new int[n]();
    int max_depth = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(edges, visited, i, depth);
            max_depth = max(max_depth, depth[i]);
        }
    }
    cout << max_depth - 1;

    delete[] edges;
    delete[] visited;
    delete[] depth;

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
