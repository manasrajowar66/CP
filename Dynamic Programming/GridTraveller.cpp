#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lli long long int
#define ll long long
#define veci vector<int>
#define for0() for (int i = 0; i < n; i++)
#define for1() for (int i = 1; i <= n; i++)
#define backloop() for (int i = n - 1; i >= 0; i--)
#define tci() \
    int t;    \
    cin >> t; \
    while (t--)
#define endl "\n"
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
int n, m;
int gridTraveller(int x, int y, vector<vector<int>> vec)
{
    if (x == n && y == m)
        return 1;
    if (x > n || y > m)
        return 0;
    if (vec[n][m] != -1)
        return vec[x][y];
    vec[x][y] = gridTraveller(x + 1, y, vec) + gridTraveller(x, y + 1, vec);
    return vec[x][y];
}

signed main()
{

    cin >> n >> m;
    vector<vector<int>> vec(n + 1, vector<int>(m + 1, -1));
    cout << gridTraveller(1, 1, vec);
    return 0;
}
