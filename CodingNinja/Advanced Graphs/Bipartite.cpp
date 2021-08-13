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

bool bipartite(vector<int> *edges, int n)
{
    unordered_set<int> sets[2];
    queue<int> pendingQueue;
    pendingQueue.push(0);
    sets[0].insert(0);
    while (!pendingQueue.empty())
    {
        int top = pendingQueue.front();
        pendingQueue.pop();
        int currentSet = sets[0].count(top) == 1 ? 0 : 1;
        for (int i = 0; i < edges[top].size(); i++)
        {
            int next = edges[top][i];
            if (sets[0].count(next) == 0 && sets[1].count(next) == 0)
            {
                sets[1 - currentSet].insert(next);
                pendingQueue.push(next);
            }
            else if (sets[currentSet].count(next) == 1)
            {
                return false;
            }
        }
    }
    for (auto x : sets[0])
    {
        cout << x + 1 << " ";
    }
    cout << endl;
    for (auto x : sets[1])
    {
        cout << x + 1 << " ";
    }
    cout << endl;
    return true;
}

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> *edges = new vector<int>[n];
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }
    bool fl = bipartite(edges, n);
    if (fl)
    {
        cout << "Colorable";
    }
    else
    {
        cout << "Not Colorable";
    }
    delete[] edges;
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
