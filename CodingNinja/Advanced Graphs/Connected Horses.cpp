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
int fact[1000001];

void dfs(int **chess, int i, int j, int n, int m, int **visited, int &count)
{
    // cout << i << "," << j << endl;
    visited[i][j] = 1;
    count++;

    //up
    if (i - 2 >= 0)
    {
        if (j - 1 >= 0 && !visited[i - 2][j - 1] && chess[i - 2][j - 1] == 1)
        {
            dfs(chess, i - 2, j - 1, n, m, visited, count);
        }
        if (j + 1 < m && !visited[i - 2][j + 1] && chess[i - 2][j + 1] == 1)
        {
            dfs(chess, i - 2, j + 1, n, m, visited, count);
        }
    }

    //down
    if (i + 2 < n)
    {
        if (j - 1 >= 0 && !visited[i + 2][j - 1] && chess[i + 2][j - 1] == 1)
        {
            dfs(chess, i + 2, j - 1, n, m, visited, count);
        }
        if (j + 1 < m && !visited[i + 2][j + 1] && chess[i + 2][j + 1] == 1)
        {
            dfs(chess, i + 2, j + 1, n, m, visited, count);
        }
    }

    //left

    if ((j - 2) >= 0)
    {
        if (i - 1 >= 0 && !visited[i - 1][j - 2] && chess[i - 1][j - 2] == 1)
        {
            dfs(chess, i - 1, j - 2, n, m, visited, count);
        }
        if (i + 1 < n && !visited[i + 1][j - 2] && chess[i + 1][j - 2] == 1)
        {
            dfs(chess, i + 1, j - 2, n, m, visited, count);
        }
    }

    //right

    if (j + 2 < m)
    {
        if (i - 1 >= 0 && !visited[i - 1][j + 2] && chess[i - 1][j + 2] == 1)
        {
            dfs(chess, i - 1, j + 2, n, m, visited, count);
        }
        if (i + 1 < n && !visited[i + 1][j + 2] && chess[i + 1][j + 2] == 1)
        {
            dfs(chess, i + 1, j + 2, n, m, visited, count);
        }
    }
}

signed main()
{
    fact[0] = 1;
    for (int i = 1; i <= 1000000; i++)
    {
        fact[i] = (i * fact[i - 1]) % Mod;
    }
    tci()
    {
        int n, m, h;
        cin >> n >> m >> h;
        int **chess = new int *[n];
        int **visited = new int *[n];
        for (int i = 0; i < n; i++)
        {
            chess[i] = new int[m];
            visited[i] = new int[m]();
            for (int j = 0; j < m; j++)
            {
                chess[i][j] = 0;
            }
        }

        while (h--)
        {
            int a, b;
            cin >> a >> b;
            chess[a - 1][b - 1] = 1;
        }
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (chess[i][j] == 1 && !visited[i][j])
                {
                    int count = 0;
                    dfs(chess, i, j, n, m, visited, count);
                    ans = (ans * fact[count]) % Mod;
                }
            }
        }

        cout << ans << endl;
        for (int i = 0; i < n; i++)
        {
            delete[] chess[i];
            delete[] visited[i];
        }
        delete[] chess;
        delete[] visited;
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
