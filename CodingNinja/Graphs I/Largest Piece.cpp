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

int find1(int **cake, int **visited, int n, int i, int j)
{
    // cout << i << "," << j << " ";
    int ans = 0;
    //up
    if (i > 0 && cake[i - 1][j] == 1 && !visited[i - 1][j])
    {
        visited[i - 1][j] = 1;
        ans = 1 + ans + find1(cake, visited, n, i - 1, j);
    }

    //down
    if (i < n - 1 && cake[i + 1][j] == 1 && !visited[i + 1][j])
    {
        visited[i + 1][j] = 1;
        ans = 1 + ans + find1(cake, visited, n, i + 1, j);
    }

    //left
    if (j > 0 && cake[i][j - 1] == 1 && !visited[i][j - 1])
    {
        visited[i][j - 1] = 1;
        ans = 1 + ans + find1(cake, visited, n, i, j - 1);
    }

    //right
    if (j < n - 1 && cake[i][j + 1] == 1 && !visited[i][j + 1])
    {
        visited[i][j + 1] = 1;
        ans = 1 + ans + find1(cake, visited, n, i, j + 1);
    }
    return ans;
}

int largestPiece(int **cake, int n, int **visited)
{
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cake[i][j] == 1 && !visited[i][j])
            {
                visited[i][j] = 1;
                int ans = 1 + find1(cake, visited, n, i, j);
                maxi = max(ans, maxi);
                // cout << endl;
            }
        }
    }
    return maxi;
}

signed main()
{
    tci()
    {
        int n;
        cin >> n;
        int **cake = new int *[n];
        int **visited = new int *[n];
        for (int i = 0; i < n; i++)
        {
            cake[i] = new int[n];
            visited[i] = new int[n]();
            string s;
            cin >> s;
            for (int j = 0; j < n; j++)
            {

                cake[i][j] = s[j] - '0';
            }
        }

        cout << largestPiece(cake, n, visited) << endl;

        for (int i = 0; i < n; i++)
        {
            delete[] cake[i];
            delete[] visited[i];
        }
        delete[] cake;
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
