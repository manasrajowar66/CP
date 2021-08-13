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
    int u, v, w;
};

bool comp(node p1, node p2)
{
    return p1.w < p2.w;
}

int findParent(int sv, int *parent)
{
    while (sv != parent[sv])
    {
        sv = parent[sv];
    }
    return sv;
}

signed main()
{
    int n, m;
    cin >> n >> m;
    node *arr = new node[m];
    node *sortArr = new node[m];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        arr[i].u = sortArr[i].u = u - 1;
        arr[i].v = sortArr[i].v = v - 1;
        arr[i].w = sortArr[i].w = w;
    }
    sort(sortArr, sortArr + m, comp);

    for (int i = 0; i < m; i++)
    {
        cout << sortArr[i].w << " " << sortArr[i].u + 1 << "," << sortArr[i].v + 1 << endl;
    }
    map<pair<int, int>, string> hash;
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        int u = sortArr[i].u;
        int v = sortArr[i].v;
        int p1 = findParent(u, parent);
        int p2 = findParent(v, parent);
        if (count < n)
        {

            if (p1 != p2)
            {
                hash[{u, v}] = "any";
                parent[p2] = p1;
            }
            else if (i > 0 && sortArr[i - 1].w == sortArr[i].w && parent[sortArr[i - 1].u] == p1 && hash[{sortArr[i - 1].u, sortArr[i - 1].v}] != "none")
            {
                hash[{sortArr[i - 1].u, sortArr[i - 1].v}] = "at least one";
                hash[{u, v}] = "at least one";
            }
            else
            {
                hash[{u, v}] = "none";
            }
        }
        else
        {
            hash[{u, v}] = "none";
        }
    }
    // for (auto x : hash)
    // {
    //     cout << x.first.first << "," << x.first.second << " " << x.second << endl;
    // }
    for (int i = 0; i < m; i++)
    {
        cout << hash[{arr[i].u, arr[i].v}] << endl;
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
