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
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define N 101
int arr[N][N], I[N][N];
void printMat(int A[][N], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void mul(int A[][N], int B[][N], int dim)
{
    int res[dim][dim];
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < dim; k++)
                res[i][j] += A[i][k] * B[k][j];
        }
    }
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            B[i][j] = res[i][j];
        }
    }
}

void power(int A[][N], int dim, int n)
{

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }

    while (n)
    {
        if (n % 2 == 1)
        {
            mul(A, I, dim);
            n--;
        }
        else
        {
            mul(A, A, dim);
            n /= 2;
        }
    }

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            A[i][j] = I[i][j];
        }
    }
}

signed main()
{
    int dim, n;
    cin >> dim >> n;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            cin >> arr[i][j];
        }
    }

    power(arr, dim, n);
    printMat(arr, dim);
    return 0;
}
