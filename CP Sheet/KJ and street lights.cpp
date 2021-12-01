//https://www.hackerrank.com/contests/ab-yeh-kar-ke-dikhao/challenges/kj-and-street-lights/problem

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
vector<int> arr;

void update(int *tree, int *lazy, int treeNode, int start, int end, int si, int ei)
{
    if (start > end)
    {
        return;
    }
    if (lazy[treeNode] != 0)
    {
        tree[treeNode] += lazy[treeNode];
        if (start != end)
        {
            lazy[treeNode * 2] += lazy[treeNode];
            lazy[treeNode * 2 + 1] += lazy[treeNode];
        }
        lazy[treeNode] = 0;
    }
    if (ei < start || si > end)
    {
        return;
    }

    if (start >= si && end <= ei)
    {
        tree[treeNode] += 1;
        if (start != end)
        {
            lazy[treeNode * 2] += 1;
            lazy[treeNode * 2 + 1] += 1;
        }
        return;
    }

    int mid = (start + end) / 2;
    update(tree, lazy, treeNode * 2, start, mid, si, ei);
    update(tree, lazy, treeNode * 2 + 1, mid + 1, end, si, ei);
    // updateTree(tree, lazy, start, mid, 2 * treeNode, startR, endR, inc_value);
    // updateTree(tree, lazy, mid + 1, end, 2 * treeNode + 1, startR, endR, inc_value);

    // tree[treeNode] = min(tree[treeNode * 2], tree[treeNode * 2 + 1]);
}

void query(int *tree, int *lazy, int start, int end, int treeNode)
{

    if (start > end)
    {
        return;
    }

    if (lazy[treeNode] != 0)
    {
        tree[treeNode] += lazy[treeNode];
        if (start != end)
        {
            lazy[treeNode * 2] += lazy[treeNode];
            lazy[treeNode * 2 + 1] += lazy[treeNode];
        }
        lazy[treeNode] = 0;
    }

    if (start == end)
    {
        if (tree[treeNode] == 1)
        {
            arr.push_back(tree[treeNode]);
            return;
        }
        else
        {
            arr.push_back(tree[treeNode]);
            return;
        }
    }

    int mid = (start + end) / 2;
    query(tree, lazy, start, mid, treeNode * 2);
    query(tree, lazy, mid + 1, end, treeNode * 2 + 1);
}

void printTree(int *node, int n)
{
    for (int i = 1; i < 2 * n; i++)
    {
        cout << node[i] << " ";
    }
    cout << endl;
}

signed main()
{
    int n, p;
    cin >> n >> p;
    int *tree = new int[4 * (p + 1)]();
    int *lazy = new int[4 * (p + 1)]();
    for (int i = 0; i < n; i++)
    {
        int xi, ri;
        cin >> xi >> ri;
        int start, end;
        if (xi - ri <= 0)
        {
            start = 0;
        }
        else
        {
            start = xi - ri;
        }
        if (xi + ri >= p)
        {
            end = p;
        }
        else
        {
            end = xi + ri;
        }
        update(tree, lazy, 1, 0, p, start, end);
    }
    // printTree(tree, p + 1);
    query(tree, lazy, 0, p, 1);

    if (arr.size() == 1 && arr[0] != 1)
    {
        cout << 1 << endl;
    }
    else if (arr.size() == 1 && arr[0] == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        int cnt = 0;
        int ans = INT_MIN;
        int size = arr.size();
        for (int i = 0; i < size; i++)
        {
            cnt = 0;
            while (arr[i] != 1 && i < size)
            {
                i++;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        cout << ans << endl;
    }
    delete[] tree;
    delete[] lazy;
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
