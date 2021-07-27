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

void updateTree(int *BIT, int index, int n, int value)
{
    for (; index <= n; index += index & (-index))
    {
        BIT[index] += value;
    }
}

int query(int *BIT, int index)
{
    int sum = 0;
    for (; index > 0; index -= index & (-index))
    {
        sum += BIT[index];
    }
    return sum;
}

signed main()
{
    int n;
    cin >> n;
    int *arr = new int[n + 1]();
    int *BIT = new int[n + 1]();
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        updateTree(BIT, i, n, arr[i]);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(BIT, r) - query(BIT, l - 1) << endl;
    }
    delete[] arr;
    delete[] BIT;
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
