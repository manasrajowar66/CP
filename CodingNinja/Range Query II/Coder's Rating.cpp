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

class coder
{
public:
    int x, y, index;
};

bool comp(coder p1, coder p2)
{
    if (p1.x == p2.x)
    {
        return p1.y < p2.y;
    }
    return p1.x < p2.x;
}

void updateTree(int *BIT, int y)
{
    for (; y <= 300000; y += y & (-y))
    {
        BIT[y]++;
    }
}

int query(int *BIT, int y)
{
    int count = 0;
    for (; y > 0; y -= y & (-y))
    {
        count += BIT[y];
    }
    return count;
}

signed main()
{
    int n;
    cin >> n;
    coder *arr = new coder[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].x >> arr[i].y;
        arr[i].index = i;
    }
    sort(arr, arr + n, comp);
    int *BIT = new int[300001]();
    int *ans = new int[n];
    for (int i = 0; i < n;)
    {
        int endIndex = i;
        while (endIndex < n && arr[i].x == arr[endIndex].x && arr[i].y == arr[endIndex].y)
        {
            endIndex++;
        }
        for (int j = i; j < endIndex; j++)
        {
            ans[arr[j].index] = query(BIT, arr[j].y);
        }
        for (int j = i; j < endIndex; j++)
        {
            updateTree(BIT, arr[j].y);
        }
        i = endIndex;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
    delete[] arr;
    delete[] BIT;
    delete[] ans;
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
