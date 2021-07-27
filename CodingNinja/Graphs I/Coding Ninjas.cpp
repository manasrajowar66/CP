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

bool isPossibleUtil(char **arr, int i, int j, string required, int n, int m, int **visited)
{
    if (required.size() == 0)
    {
        return true;
    }
    if (i > 0 && j > 0 && arr[i - 1][j - 1] == required[0] && !visited[i - 1][j - 1])
    {
        visited[i - 1][j - 1] = 1;
        bool ans = isPossibleUtil(arr, i - 1, j - 1, required.substr(1), n, m, visited);
        if (ans)
        {
            return ans;
        }
        visited[i - 1][j - 1] = 0;
    }
    if (i > 0 && arr[i - 1][j] == required[0] && !visited[i - 1][j])
    {
        visited[i - 1][j] = 1;
        bool ans = isPossibleUtil(arr, i - 1, j, required.substr(1), n, m, visited);
        if (ans)
        {
            return ans;
        }
        visited[i - 1][j] = 0;
    }
    if (i > 0 && j < m - 1 && arr[i - 1][j + 1] == required[0] && !visited[i - 1][j + 1])
    {
        visited[i - 1][j + 1] = 1;
        bool ans = isPossibleUtil(arr, i - 1, j + 1, required.substr(1), n, m, visited);
        if (ans)
        {
            return ans;
        }
        visited[i - 1][j + 1] = 0;
    }
    if (j > 0 && arr[i][j - 1] == required[0] && !visited[i][j - 1])
    {
        visited[i][j - 1] = 1;
        bool ans = isPossibleUtil(arr, i, j - 1, required.substr(1), n, m, visited);
        if (ans)
        {
            return ans;
        }
        visited[i][j - 1] = 0;
    }
    if (j < m - 1 && arr[i][j + 1] == required[0] && !visited[i][j + 1])
    {
        visited[i][j + 1] = 1;
        bool ans = isPossibleUtil(arr, i, j + 1, required.substr(1), n, m, visited);
        if (ans)
        {
            return ans;
        }
        visited[i][j + 1] = 0;
    }
    if (i < n - 1 && j > 0 && arr[i + 1][j - 1] == required[0] && !visited[i + 1][j - 1])
    {
        visited[i + 1][j - 1] = 1;
        bool ans = isPossibleUtil(arr, i + 1, j - 1, required.substr(1), n, m, visited);
        if (ans)
        {
            return ans;
        }
        visited[i + 1][j - 1] = 0;
    }
    if (i < n - 1 && arr[i + 1][j] == required[0] && !visited[i + 1][j])
    {
        visited[i + 1][j] = 1;
        bool ans = isPossibleUtil(arr, i + 1, j, required.substr(1), n, m, visited);
        if (ans)
        {
            return ans;
        }
        visited[i + 1][j] = 0;
    }
    if (i < n - 1 && j < m - 1 && arr[i + 1][j + 1] == required[0] && !visited[i + 1][j + 1])
    {
        visited[i + 1][j + 1] = 1;
        bool ans = isPossibleUtil(arr, i + 1, j + 1, required.substr(1), n, m, visited);
        if (ans)
        {
            return ans;
        }
        visited[i + 1][j + 1] = 0;
    }
    return false;
}

bool isPossible(char **arr, int n, int m, int **visited)
{
    string required = "CODINGNINJA";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'C')
            {
                visited[i][j] = 1;
                bool ans = isPossibleUtil(arr, i, j, required.substr(1), n, m, visited);
                if (ans)
                {
                    return true;
                }
                visited[i][j] = 0;
            }
        }
    }
    return false;
}

signed main()
{
    tci()
    {
        int n, m;
        cin >> n >> m;
        char **arr = new char *[n];
        int **visited = new int *[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new char[m];
            visited[i] = new int[m]();
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = s[j];
            }
        }
        if (isPossible(arr, n, m, visited))
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        for (int i = 0; i < n; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
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
