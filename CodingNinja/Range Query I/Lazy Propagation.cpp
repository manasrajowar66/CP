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

void buildTree(int *arr, int *tree, int start, int end, int treeNode)
{
    if (start == end)
    {
        tree[treeNode] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);
    tree[treeNode] = min(tree[treeNode * 2], tree[treeNode * 2 + 1]);
}

void updateTree(int *tree, int *lazy, int start, int end, int treeNode, int startR, int endR, int inc_value)
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

    if (start > endR || end < startR)
    {
        return;
    }

    if (start >= startR && end <= endR)
    {
        tree[treeNode] += inc_value;
        if (start != end)
        {
            lazy[treeNode * 2] += inc_value;
            lazy[treeNode * 2 + 1] += inc_value;
        }
        return;
    }

    int mid = (start + end) / 2;

    updateTree(tree, lazy, start, mid, 2 * treeNode, startR, endR, inc_value);
    updateTree(tree, lazy, mid + 1, end, 2 * treeNode + 1, startR, endR, inc_value);

    tree[treeNode] = min(tree[treeNode * 2], tree[treeNode * 2 + 1]);
}

int query(int *tree, int *lazy, int start, int end, int treeNode, int left, int right)
{

    if (start > end)
    {
        return INT_MAX;
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

    //completely outside
    if (start > right || end < left)
    {
        return INT_MAX;
    }
    //completely inside
    if (start >= left && end <= right)
    {
        return tree[treeNode];
    }
    //partialy inside
    int mid = (start + end) / 2;
    int ans1 = query(tree, lazy, start, mid, treeNode * 2, left, right);
    int ans2 = query(tree, lazy, mid + 1, end, treeNode * 2 + 1, left, right);
    return min(ans1, ans2);
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
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int *tree = new int[2 * n];
    int *lazy = new int[2 * n];
    memset(lazy, 0, sizeof(lazy));

    for (int i = 1; i < 2 * n; i++)
    {
        lazy[i] = 0;
    }

    buildTree(arr, tree, 0, n - 1, 1);

    cout << "Segment Tree After Build:" << endl;
    printTree(tree, n);
    cout << "Lazy Tree Tree:" << endl;
    printTree(lazy, n);
    cout << query(tree, lazy, 0, n - 1, 1, 0, 2) << endl;

    updateTree(tree, lazy, 0, n - 1, 1, 0, 3, 2);

    cout << "Segment Tree After Update:" << endl;
    printTree(tree, n);
    cout << "Lazy Tree Tree:" << endl;
    printTree(lazy, n);
    cout << query(tree, lazy, 0, n - 1, 1, 1, 2) << endl;

    updateTree(tree, lazy, 0, n - 1, 1, 0, 1, 3);

    cout << "Segment Tree After Update:" << endl;
    printTree(tree, n);
    cout << "Lazy Tree Tree:" << endl;
    printTree(lazy, n);

    cout << query(tree, lazy, 0, n - 1, 1, 0, 0) << endl;

    updateTree(tree, lazy, 0, n - 1, 1, 1, 2, 1);

    cout << "Segment Tree After Update:" << endl;
    printTree(tree, n);
    cout << "Lazy Tree Tree:" << endl;
    printTree(lazy, n);

    cout << query(tree, lazy, 0, n - 1, 1, 1, 2) << endl;

    cout << query(tree, lazy, 0, n - 1, 1, 1, 3) << endl;
    delete[] arr;
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
