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

bool getPath(int **edges, int sv, int des, int v, int *visited, int *path, int &pathSize)
{
    path[pathSize] = sv;
    pathSize++;
    visited[sv] = 1;

    if (sv == des)
    {
        return true;
    }

    for (int i = 0; i < v; i++)
    {
        if (sv == i)
        {
            continue;
        }

        if (edges[sv][i] == 1 && !visited[i])
        {

            bool ans = getPath(edges, i, des, v, visited, path, pathSize);
            if (ans)
            {
                return ans;
            }
            pathSize--;
        }
    }
    return false;
}

signed main()
{
    tci()
    {
        int v, e;
        cin >> v >> e;
        int **edges = new int *[v];
        for (int i = 0; i < v; i++)
        {
            edges[i] = new int[v]();
        }
        while (e--)
        {
            int a, b;
            cin >> a >> b;
            edges[a][b] = 1;
            edges[b][a] = 1;
        }
        int sour, des;
        cin >> sour >> des;
        int *visited = new int[v]();
        int *path = new int[v]();
        int pathSize = 0;
        if (getPath(edges, sour, des, v, visited, path, pathSize))
        {
            for (int i = pathSize - 1; i >= 0; i--)
            {
                cout << path[i] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < v; i++)
        {
            delete[] edges[i];
        }
        delete[] edges;
        delete[] visited;
        delete[] path;
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
