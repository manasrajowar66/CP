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

class node
{
public:
    int weight, u, v;
};

bool comp(node p1, node p2)
{
    if (p1.weight != p2.weight)
    {
        return p1.weight < p2.weight;
    }
    if (p1.u != p2.u)
    {
        return p1.u < p2.u;
    }
    return p1.v <= p2.v;
}

int findParent(int v, int *parent)
{
    while (parent[v] != v)
    {
        v = parent[v];
    }
    return v;
}

void dfs(int sv, vector<int> *edges, int *visited)
{
    // cout << sv << " ";
    visited[sv] = 1;
    for (int i = 0; i < edges[sv].size(); i++)
    {
        int next = edges[sv][i];
        if (!visited[next])
        {
            dfs(next, edges, visited);
        }
    }
}

int findComponents(vector<int> *edges, int v)
{
    int *visited = new int[v]();
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, edges, visited);
            count++;
        }
    }
    delete[] visited;
    return count;
}

signed main()
{
    tci()
    {
        int v, e, val;
        cin >> v >> e >> val;
        node *edges = new node[e];
        vector<int> *edgesUtil = new vector<int>[v];
        int *parent = new int[v];
        for (int i = 0; i < e; i++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            edges[i].u = a - 1;
            edges[i].v = b - 1;
            edges[i].weight = w;
            edgesUtil[a - 1].push_back(b - 1);
            edgesUtil[b - 1].push_back(a - 1);
        }
        int components = findComponents(edgesUtil, v);
        for (int i = 0; i < v; i++)
        {
            parent[i] = i;
        }
        sort(edges, edges + e, comp);
        // for (int i = 0; i < e; i++)
        // {
        //     cout << edges[i].u << " " << edges[i].v << " " << edges[i].weight << endl;
        // }
        int count = 0;
        int curr_ind = 0;
        int minWeight = 0;
        while (count < v - 1 && curr_ind < e)
        {
            int v1 = edges[curr_ind].u;
            int v2 = edges[curr_ind].v;
            int p1 = findParent(v1, parent);
            int p2 = findParent(v2, parent);
            int weight = edges[curr_ind].weight;
            if (p1 != p2)
            {
                // cout << v1 << "," << v2 << " " << p1 << "," << p2 << endl;
                parent[p2] = p1;
                minWeight += min(weight, val);
                count++;
            }
            curr_ind++;
        }
        cout << minWeight + components * val << endl;
        delete[] parent;
        delete[] edges;
        delete[] edgesUtil;
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
