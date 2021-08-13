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

void dfs(vector<int> *edges, int sv, stack<int> &st, int *visited)
{
    visited[sv] = 1;
    for (int i = 0; i < edges[sv].size(); i++)
    {
        int next = edges[sv][i];
        if (!visited[next])
        {
            dfs(edges, next, st, visited);
        }
    }
    st.push(sv);
}

void print(vector<int> *edges, int sv, int n, int *visited, unordered_set<int> *component)
{
    visited[sv] = 1;
    component->insert(sv);
    for (int i = 0; i < edges[sv].size(); i++)
    {
        int next = edges[sv][i];
        if (!visited[next])
        {
            print(edges, next, n, visited, component);
        }
    }
}

signed main()
{
    tci()
    {
        int n, m;
        cin >> n >> m;
        vector<int> *edges = new vector<int>[n];
        vector<int> *edgesT = new vector<int>[n];
        int *visited = new int[n]();
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            edges[a - 1].push_back(b - 1);
            edgesT[b - 1].push_back(a - 1);
        }
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(edges, i, st, visited);
            }
        }
        for (int i = 0; i < n; i++)
        {
            visited[i] = 0;
        }
        unordered_set<unordered_set<int> *> *components = new unordered_set<unordered_set<int> *>();
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            if (!visited[top])
            {
                unordered_set<int> *component = new unordered_set<int>;
                print(edgesT, top, n, visited, component);
                components->insert(component);
            }
        }

        unordered_set<unordered_set<int> *>::iterator it = components->begin();
        set<int> ans;

        while (it != components->end())
        {
            bool fl = false;
            unordered_set<int> *component = *it;
            unordered_set<int>::iterator it2 = component->begin();
            while (it2 != component->end())
            {
                for (int i = 0; i < edges[*it2].size(); i++)
                {
                    int connectedElement = edges[*it2][i];
                    if (component->count(connectedElement) == 0)
                    {
                        fl = true;
                    }
                }
                it2++;
            }
            if (!fl)
            {
                it2 = component->begin();
                while (it2 != component->end())
                {
                    ans.insert(*it2 + 1);
                    it2++;
                }
            }
            it++;
            delete component;
        }
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
        delete[] edges;
        delete[] edgesT;
        delete[] visited;
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
