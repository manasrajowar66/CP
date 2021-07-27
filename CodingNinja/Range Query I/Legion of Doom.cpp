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

// void buildTree(int* tree,int* lazy,int start,int end,int treeNode){
//     if(start == end){

//     }
// }

void updateTree(int *tree, int *lazy, int start, int end, int treeNode, int left, int right, int add_value)
{
    if (start > end)
    {
        return;
    }

    if (lazy[treeNode] != 0)
    {
        tree[treeNode] += (end - start + 1) * lazy[treeNode];
        if (start != end)
        {
            lazy[treeNode * 2] += lazy[treeNode];
            lazy[treeNode * 2 + 1] += lazy[treeNode];
        }
        lazy[treeNode] = 0;
    }

    if (start > right || end < left)
    {
        return;
    }

    if (start >= left && end <= right)
    {
        tree[treeNode] += (end - start + 1) * add_value;
        if (start != end)
        {
            lazy[treeNode * 2] += add_value;
            lazy[treeNode * 2 + 1] += add_value;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateTree(tree, lazy, start, mid, treeNode * 2, left, right, add_value);
    updateTree(tree, lazy, mid + 1, end, treeNode * 2 + 1, left, right, add_value);
    tree[treeNode] = (tree[treeNode * 2] + tree[treeNode * 2 + 1]);
}

int query(int *tree, int *lazy, int start, int end, int treeNode, int left, int right)
{
    if (lazy[treeNode] != 0)
    {
        tree[treeNode] += (end - start + 1) * lazy[treeNode];
        if (start != end)
        {
            lazy[treeNode * 2] += lazy[treeNode];
            lazy[treeNode * 2 + 1] += lazy[treeNode];
        }
        lazy[treeNode] = 0;
    }

    if (start > right || end < left)
    {
        return 0;
    }

    if (start >= left && end <= right)
    {
        return tree[treeNode];
    }
    int mid = (start + end) / 2;
    int ans1 = query(tree, lazy, start, mid, treeNode * 2, left, right);
    int ans2 = query(tree, lazy, mid + 1, end, treeNode * 2 + 1, left, right);
    return (ans1 + ans2);
}

signed main()
{
    tci()
    {
        int n, q;
        cin >> n >> q;
        int *tree = new int[4 * n];
        int *lazy = new int[4 * n];
        for (int i = 1; i < 4 * n; i++)
        {
            tree[i] = 0;
            lazy[i] = 0;
        }

        while (q--)
        {
            int type;
            cin >> type;
            if (type == 0)
            {
                int l, r, value;
                cin >> l >> r >> value;
                updateTree(tree, lazy, 0, n - 1, 1, l - 1, r - 1, value);
            }
            else
            {
                int l, r;
                cin >> l >> r;
                cout << query(tree, lazy, 0, n - 1, 1, l - 1, r - 1) << endl;
            }
        }

        delete[] tree;
        delete[] lazy;
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
