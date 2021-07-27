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

void DFS(int **edges, int sv, int n, int *visited)
{
    cout << sv << endl;
    visited[sv] = 1;
    for (int i = 0; i < n; i++)
    {
        if (sv == i)
        {
            continue;
        }
        if (!visited[i] && edges[sv][i])
        {
            DFS(edges, i, n, visited);
        }
    }
}

void BFS(int **edges, int sv, int n, int *visited)
{
    queue<int> arr;
    cout << sv << " ";
    visited[sv] = 1;
    for (int i = 0; i < n; i++)
    {
        if (sv == i)
        {
            continue;
        }
        if (!visited[i] && edges[sv][i])
        {
            arr.push(i);
            visited[i] = 1;
        }
    }
    while (!arr.empty())
    {
        sv = arr.front();
        arr.pop();
        cout << sv << " ";
        for (int i = 0; i < n; i++)
        {
            if (sv == i)
            {
                continue;
            }
            if (!visited[i] && edges[sv][i])
            {
                arr.push(i);
                visited[i] = 1;
            }
        }
    }
}

signed main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    while (e--)
    {
        int v, u;
        cin >> v >> u;
        edges[v][u] = 1;
        edges[u][v] = 1;
    }
    int *visited = new int[n]();
    BFS(edges, 0, n, visited);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            BFS(edges, i, n, visited);
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;
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
