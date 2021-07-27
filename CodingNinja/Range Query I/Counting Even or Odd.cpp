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

struct node
{
    int count_of_even;
    int count_of_odd;
};
void buildTree(int *arr, node *tree, int start, int end, int treeNode)
{
    if (start == end)
    {
        if (arr[start] & 1)
        {
            tree[treeNode].count_of_even = 0;
            tree[treeNode].count_of_odd = 1;
        }
        else
        {
            tree[treeNode].count_of_even = 1;
            tree[treeNode].count_of_odd = 0;
        }
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);
    tree[treeNode].count_of_even = tree[treeNode * 2].count_of_even + tree[treeNode * 2 + 1].count_of_even;
    tree[treeNode].count_of_odd = tree[treeNode * 2].count_of_odd + tree[treeNode * 2 + 1].count_of_odd;
}

void updateTree(int *arr, node *tree, int start, int end, int treeNode, int update_ind, int new_value)
{
    if (start == end)
    {
        if (start == update_ind)
        {
            arr[start] = new_value;
            if (arr[start] & 1)
            {
                tree[treeNode].count_of_even = 0;
                tree[treeNode].count_of_odd = 1;
            }
            else
            {
                tree[treeNode].count_of_even = 1;
                tree[treeNode].count_of_odd = 0;
            }
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
    tree[treeNode].count_of_even = tree[treeNode * 2].count_of_even + tree[treeNode * 2 + 1].count_of_even;
    tree[treeNode].count_of_odd = tree[treeNode * 2].count_of_odd + tree[treeNode * 2 + 1].count_of_odd;
}

node query(node *tree, int start, int end, int treeNode, int left, int right)
{

    //completely outside
    if (start > right || end < left)
    {
        node temp;
        temp.count_of_even = 0;
        temp.count_of_odd = 0;
        return temp;
    }
    //completely inside
    if (start >= left && end <= right)
    {
        return tree[treeNode];
    }
    //partialy inside
    int mid = (start + end) / 2;
    node ans1 = query(tree, start, mid, treeNode * 2, left, right);
    node ans2 = query(tree, mid + 1, end, treeNode * 2 + 1, left, right);
    node ans;
    ans.count_of_even = ans1.count_of_even + ans2.count_of_even;
    ans.count_of_odd = ans1.count_of_odd + ans2.count_of_odd;
    return ans;
}

signed main()
{
    int n, q;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    node *tree = new node[2 * n];
    buildTree(arr, tree, 0, n - 1, 1);
    // for (int i = 1; i < 2 * n; i++)
    // {
    //     cout << tree[i] << " ";
    // }
    // cout << endl;
    cin >> q;
    while (q--)
    {
        int x;
        int l, r;
        cin >> x >> l >> r;
        if (x == 0)
        {
            updateTree(arr, tree, 0, n - 1, 1, l - 1, r);
        }
        else if (x == 1)
        {
            cout << query(tree, 0, n - 1, 1, l - 1, r - 1).count_of_even << endl;
        }
        else
        {
            cout << query(tree, 0, n - 1, 1, l - 1, r - 1).count_of_odd << endl;
        }
    }

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
