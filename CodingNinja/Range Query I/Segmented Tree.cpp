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
    tree[treeNode] = tree[treeNode * 2] + tree[treeNode * 2 + 1];
}

void updateTree(int *arr, int *tree, int start, int end, int treeNode, int update_ind, int new_value)
{
    if (start == end)
    {
        if (start == update_ind)
        {
            arr[start] = new_value;
            tree[treeNode] = new_value;
        }
        return;
    }
    int mid = (start + end) / 2;
    if (update_ind <= mid)
    {
        updateTree(arr, tree, start, mid, 2 * treeNode, update_ind, new_value);
    }
    else
    {
        updateTree(arr, tree, mid + 1, end, 2 * treeNode + 1, update_ind, new_value);
    }
    tree[treeNode] = tree[treeNode * 2] + tree[treeNode * 2 + 1];
}

int query(int *tree, int start, int end, int treeNode, int left, int right)
{

    //completely outside
    if (start > right || end < left)
    {
        return 0;
    }
    //completely inside
    if (start >= left && end <= right)
    {
        return tree[treeNode];
    }
    //partialy inside
    int mid = (start + end) / 2;
    int ans1 = query(tree, start, mid, treeNode * 2, left, right);
    int ans2 = query(tree, mid + 1, end, treeNode * 2 + 1, left, right);
    return ans1 + ans2;
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
    int *tree = new int[4 * n];
    buildTree(arr, tree, 0, n - 1, 1);
    for (int i = 1; i < 2 * n; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
    updateTree(arr, tree, 0, n - 1, 1, 2, 10);
    for (int i = 1; i < 2 * n; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
    cout << query(tree, 0, n - 1, 1, 1, 3) << endl;
    delete[] arr;
    delete[] tree;
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
