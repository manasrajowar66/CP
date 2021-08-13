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

// struct node
// {
//     int index, val;
// };

// struct myComp
// {
//     bool operator()(node p1, node p2)
//     {
//         return p1.val < p2.val;
//     }
// };

// int minDistInd(int *dist, int *visited, int n)
// {
//     int ind = -1;
//     int minval = INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i] && minval > dist[i])
//         {
//             ind = i;
//             minval = dist[i];
//         }
//     }
//     return ind;
// }

int findMinPath(int sv, vector<int> *edges, int n, int *visited, int *dist)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    dist[sv] = 0;
    pq.push({0, sv});

    while (!pq.empty())
    {
        int ind = pq.top().second;
        pq.pop();
        if (!visited[ind])
        {
            for (int j = 0; j < edges[ind].size(); j++)
            {
                int next = edges[ind][j];
                if (!visited[next] && dist[ind] + 1 < dist[next])
                {
                    dist[next] = dist[ind] + 1;
                    pq.push({dist[next], next});
                }
            }
        }
        visited[ind] = 1;
    }
    return dist[n - 1];
}

signed main()
{
    tci()
    {
        int n, m;
        cin >> n >> m;
        vector<int> *edges = new vector<int>[n];
        int *visited = new int[n];
        int *dist = new int[n];
        for (int i = 0; i < n; i++)
        {
            visited[i] = 0;
            dist[i] = INT_MAX;
        }
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            edges[a - 1].push_back(b - 1);
            edges[b - 1].push_back(a - 1);
        }
        cout << findMinPath(0, edges, n, visited, dist) << endl;
        delete[] edges;
        delete[] visited;
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
