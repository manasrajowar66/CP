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

class node
{
public:
    int a, b, w;
};

signed main()
{
    tci()
    {
        int v, e;
        cin >> v >> e;
        node *edges = new node[e];
        int src, des;
        cin >> src >> des;
        for (int i = 0; i < e; i++)
        {
            cin >> edges[i].a >> edges[i].b >> edges[i].w;
        }
        int *dist = new int[v + 1];
        for (int i = 0; i <= v; i++)
        {
            dist[i] = INT_MAX;
        }
        dist[src] = 0;
        for (int i = 0; i < v - 1; i++)
        {
            for (int j = 0; j < e; j++)
            {
                if (dist[edges[j].a] != INT_MAX && dist[edges[j].a] + edges[j].w < dist[edges[j].b])
                {
                    dist[edges[j].b] = dist[edges[j].a] + edges[j].w;
                }
            }
        }
        // bool fl = false;

        // for (int j = 0; j < e; j++)
        // {
        //     if (dist[edges[j].a] + edges[j].w < dist[edges[j].b])
        //     {
        //         fl = true;
        //         break;
        //     }
        // }
        if (dist[des] == INT_MAX)
        {
            cout << Max << endl;
        }
        else
        {
            cout << dist[des] << endl;
        }
        delete[] edges;
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
