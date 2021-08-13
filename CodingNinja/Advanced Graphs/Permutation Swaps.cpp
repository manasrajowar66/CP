#include <bits/stdc++.h>
#include <unordered_set>
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

void dfs(vector<int> *edges, int sv, bool *visited, unordered_set<int> *component)
{
    visited[sv] = true;
    component->insert(sv);
    for (int i = 0; i < edges[sv].size(); i++)
    {
        int next = edges[sv][i];
        if (!visited[next])
        {
            dfs(edges, next, visited, component);
        }
    }
}

unordered_set<unordered_set<int> *> *findConnectedComponents(vector<int> *edges, int n)
{
    bool *visited = new bool[n]();
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    unordered_set<unordered_set<int> *> *components = new unordered_set<unordered_set<int> *>;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            unordered_set<int> *component = new unordered_set<int>;
            dfs(edges, i, visited, component);
            components->insert(component);
        }
    }
    delete[] visited;
    return components;
}

void print(unordered_set<unordered_set<int> *> *components)
{
    unordered_set<unordered_set<int> *>::iterator it = components->begin();
    while (it != components->end())
    {
        unordered_set<int> *component = *it;
        unordered_set<int>::iterator it2 = component->begin();
        while (it2 != component->end())
        {
            cout << *it2 + 1 << " ";
            it2++;
        }
        cout << endl;
        it++;
    }
}
signed main()
{
    tci()
    {
        int n, e;
        cin >> n >> e;
        int *p = new int[n];
        int *q = new int[n];
        vector<int> *edges = new vector<int>[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> q[i];
        }
        while (e--)
        {
            int a, b;
            cin >> a >> b;
            edges[a - 1].push_back(b - 1);
            edges[b - 1].push_back(a - 1);
        }
        unordered_set<unordered_set<int> *> *components = findConnectedComponents(edges, n);
        unordered_set<unordered_set<int> *>::iterator it = components->begin();
        bool fl = true;
        // print(components);
        while (it != components->end())
        {
            unordered_set<int> *component = *it;
            map<int, int> hash;
            unordered_set<int>::iterator it2 = component->begin();
            while (it2 != component->end())
            {
                hash[p[*it2]]++;
                it2++;
            }
            it2 = component->begin();
            while (it2 != component->end())
            {
                if (hash[q[*it2]] <= 0)
                {
                    fl = false;
                    break;
                }
                else
                {
                    hash[q[*it2]]--;
                }
                it2++;
            }
            it++;
            delete component;
        }
        if (fl)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        delete[] edges;
        delete[] p;
        delete[] q;
        delete components;
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
