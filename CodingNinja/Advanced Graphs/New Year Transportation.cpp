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

void dfs(int sv, vector<int> *edges, int *visited, int *parent)
{
    // cout << sv << " ";
    parent[sv] = 1;
    visited[sv] = 1;
    for (int i = 0; i < edges[sv].size(); i++)
    {
        int next = edges[sv][i];
        if (!visited[next])
        {
            dfs(next, edges, visited, parent);
        }
    }
}

signed main()
{
    tci()
    {
        int n;
        cin >> n;
        vector<int> *edges = new vector<int>[n + 1];
        for (int i = 1; i < n; i++)
        {
            int x;
            cin >> x;
            edges[i].push_back(i + x);
        }
        int q;
        cin >> q;
        int *visited = new int[n + 1]();
        int *parent = new int[n + 1];
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        dfs(1, edges, visited, parent);
        while (q--)
        {
            int x;
            cin >> x;
            if (parent[x] == 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        delete[] edges;
        delete[] visited;
        delete[] parent;
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
