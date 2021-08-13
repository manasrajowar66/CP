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
    int index, val;
};

bool comp(node p1, node p2)
{
    return (p1.val < p2.val);
}

signed main()
{
    tci()
    {
        int n, k;
        cin >> n >> k;
        int Val = 100;
        if (k >= 100 || k >= n)
        {
            k = min(Val, n);
        }
        node *arr = new node[n];
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr[i].val = x;
            arr[i].index = i + 1;
        }

        sort(arr, arr + n, comp);
        int ans = INT_MIN;
        for (int i = 0; i < n - 1; i++)
        {
            ans = max((arr[i].index * arr[i + 1].index) - k * (arr[i].val | arr[i + 1].val), ans);
            // cout << arr[i].index << " " << arr[i].val << endl;
        }
        cout << ans << endl;
        delete[] arr;
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
