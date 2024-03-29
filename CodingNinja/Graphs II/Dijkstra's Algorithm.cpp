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
typedef pair<int, int> iPair;
int power(int, int);
bool isPrime(int);

int findMinDist(int *dist, int v, int *visited)
{
    int ind = -1;
    int min_dist = LLONG_MAX;
    for (int i = 0; i < v; i++)
    {
        if (min_dist > dist[i] && !visited[i])
        {
            min_dist = dist[i];
            ind = i;
        }
    }
    return ind;
}

signed main()
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
            int a, b, d;
            cin >> a >> b >> d;
            if (edges[a - 1][b - 1] == 0 || edges[a - 1][b - 1] > d)
            {
                edges[a - 1][b - 1] = d;
                edges[b - 1][a - 1] = d;
            }
        }
        int *dist = new int[v];
        int *visited = new int[v]();
        for (int i = 0; i < v; i++)
        {
            dist[i] = LLONG_MAX;
        }
        // priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        dist[0] = 0;
        // pq.push({0, 0});

        for (int j = 0; j < v - 1; j++)
        {
            int sv = findMinDist(dist, v, visited);
            if (sv == -1)
            {
                break;
            }
            // int sv = pq.top().second;
            // pq.pop();
            for (int i = 0; i < v; i++)
            {
                if (sv != i && edges[sv][i] != 0 && !visited[i])
                {
                    dist[i] = min(dist[i], (dist[sv] + (sv + 1) * edges[sv][i]));
                    // pq.push({dist[i], i});
                }
            }
            visited[sv] = 1;
        }
        for (int i = 0; i < v; i++)
        {
            if (dist[i] == LLONG_MAX)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << dist[i] << endl;
            }
        }
        for (int i = 0; i < v; i++)
        {
            delete[] edges[i];
        }
        delete[] edges;
        delete[] dist;
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
