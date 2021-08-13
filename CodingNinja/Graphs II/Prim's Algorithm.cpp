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

int findMinWeight(int *weight, int *visited, int v)
{
    int ind = -1;
    int mini = INT_MAX;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && weight[i] < mini)
        {
            mini = weight[i];
            ind = i;
        }
    }
    return ind;
}

signed main()
{
    tci()
    {
        int v, e;
        cin >> v >> e;
        int *parent = new int[v];
        int *weight = new int[v];
        int *visited = new int[v];
        int **edges = new int *[v];
        for (int i = 0; i < v; i++)
        {
            edges[i] = new int[v]();
        }

        for (int i = 0; i < v; i++)
        {
            parent[i] = -1;
            weight[i] = INT_MAX;
            visited[i] = 0;
        }

        while (e--)
        {
            int a, b, w;
            cin >> a >> b >> w;
            if (edges[a][b] != 0 && edges[a][b] <= w)
            {
                continue;
            }
            else
            {
                edges[a][b] = w;
                edges[b][a] = w;
            }
        }
        weight[0] = 0;
        parent[0] = 0;
        while (1)
        {
            int sv = findMinWeight(weight, visited, v);
            if (sv == -1)
            {
                break;
            }
            for (int i = 0; i < v; i++)
            {
                if (edges[sv][i] != 0 && !visited[i] && edges[sv][i] < weight[i])
                {
                    weight[i] = edges[sv][i];
                    parent[i] = sv;
                }
            }
            visited[sv] = 1;
        }
        int sum = 0;
        for (int i = 0; i < v; i++)
        {
            sum += weight[i];
        }
        cout << sum << endl;
        for (int i = 0; i < v; i++)
        {
            delete[] edges[i];
        }
        delete[] edges;
        delete[] weight;
        delete[] parent;
        delete[] visited;
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
