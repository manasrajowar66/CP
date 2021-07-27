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

bool isPossibleUtil(char **board, int **visited, int n, int m, int i, int j, int count)
{
    //up
    if (i > 0 && board[i - 1][j] == board[i][j])
    {
        if (!visited[i - 1][j])
        {
            visited[i - 1][j] = 1;
            bool ans = isPossibleUtil(board, visited, n, m, i - 1, j, count + 1);
            if (ans)
            {
                return ans;
            }
            visited[i - 1][j] = 0;
        }
        else if (visited[i - 1][j] == 1 && count >= 4)
        {
            return true;
        }
    }
    //down
    if (i < n - 1 && board[i + 1][j] == board[i][j])
    {
        if (!visited[i + 1][j])
        {
            visited[i + 1][j] = 1;
            bool ans = isPossibleUtil(board, visited, n, m, i + 1, j, count + 1);
            if (ans)
            {
                return ans;
            }
            visited[i + 1][j] = 0;
        }
        else if (visited[i + 1][j] == 1 && count >= 4)
        {
            return true;
        }
    }
    //left
    if (j > 0 && board[i][j - 1] == board[i][j])
    {
        if (!visited[i][j - 1])
        {
            visited[i][j - 1] = 1;
            bool ans = isPossibleUtil(board, visited, n, m, i, j - 1, count + 1);
            if (ans)
            {
                return ans;
            }
            visited[i][j - 1] = 0;
        }
        else if (visited[i][j - 1] == 1 && count >= 4)
        {
            return true;
        }
    }
    //right
    if (j < m - 1 && board[i][j + 1] == board[i][j])
    {
        if (!visited[i][j + 1])
        {
            visited[i][j + 1] = 1;
            bool ans = isPossibleUtil(board, visited, n, m, i, j + 1, count + 1);
            if (ans)
            {
                return true;
            }
            visited[i][j + 1] = 0;
        }
        else if (visited[i][j + 1] == 1 && count >= 4)
        {
            return true;
        }
    }
    return false;
}

bool isPossible(char **board, int **visited, int n, int m)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = 1;
            bool ans = isPossibleUtil(board, visited, n, m, i, j, 0);
            if (ans)
            {
                return true;
            }
            visited[i][j] = 0;
        }
    }
    return false;
}

signed main()
{
    int n, m;
    cin >> n >> m;
    char **board = new char *[n];
    int **visited = new int *[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new char[m];
        visited[i] = new int[m];
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            board[i][j] = s[j];
        }
    }

    if (isPossible(board, visited, n, m))
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] board[i];
        delete[] visited[i];
    }
    delete[] board;
    delete[] visited;
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
