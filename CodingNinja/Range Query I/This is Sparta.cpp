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
    int strength = 0;
    int cowardice = 0;
};

class node2
{
public:
    int strength = 0;
    int cowardice = 0;
    int index = 0;
    void clone(node2 tree)
    {
        strength = tree.strength;
        cowardice = tree.cowardice;
        index = tree.index;
        return;
    }
};

void buildTree(node *arr, node2 *tree, int start, int end, int treeNode)
{
    if (start == end)
    {
        tree[treeNode].strength = arr[start].strength;
        tree[treeNode].cowardice = arr[start].cowardice;
        tree[treeNode].index = start;
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, treeNode * 2);
    buildTree(arr, tree, mid + 1, end, treeNode * 2 + 1);
    if (tree[treeNode * 2].strength > tree[treeNode * 2 + 1].strength)
    {
        tree[treeNode].clone(tree[treeNode * 2]);
    }
    else if (tree[treeNode * 2].strength < tree[treeNode * 2 + 1].strength)
    {
        tree[treeNode].clone(tree[treeNode * 2 + 1]);
    }
    else if (tree[treeNode * 2].cowardice < tree[treeNode * 2 + 1].cowardice)
    {
        tree[treeNode].clone(tree[treeNode * 2]);
        // tree[treeNode] = tree[treeNode * 2];
    }
    else if (tree[treeNode * 2].cowardice > tree[treeNode * 2 + 1].cowardice)
    {
        tree[treeNode].clone(tree[treeNode * 2 + 1]);
        // tree[treeNode] = tree[treeNode * 2 + 1];
    }
    else
    {
        tree[treeNode].clone(tree[treeNode * 2]);
        // tree[treeNode] = tree[treeNode * 2];
    }
}

node2 query(node2 *tree, int start, int end, int treeNode, int left, int right)
{
    if (start > right || end < left)
    {
        node2 temp;
        temp.strength = INT_MIN;
        temp.cowardice = INT_MAX;
        return temp;
    }

    if (start >= left && end <= right)
    {
        return tree[treeNode];
    }

    int mid = (start + end) / 2;
    node2 ans1 = query(tree, start, mid, treeNode * 2, left, right);
    node2 ans2 = query(tree, mid + 1, end, treeNode * 2 + 1, left, right);
    node2 ans;

    if (ans1.strength > ans2.strength)
    {
        ans.clone(ans1);
    }
    else if (ans1.strength < ans2.strength)
    {
        ans.clone(ans2);
    }
    else if (ans1.cowardice < ans2.cowardice)
    {
        ans.clone(ans1);
    }
    else if (ans1.cowardice > ans2.cowardice)
    {
        ans.clone(ans2);
    }
    else
    {
        ans.clone(ans1);
    }
    return ans;
}

signed main()
{
    int n;
    cin >> n;
    node *arr = new node[4 * n];
    node2 *tree = new node2[4 * n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].strength;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].cowardice;
    }
    buildTree(arr, tree, 0, n - 1, 1);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(tree, 0, n - 1, 1, l - 1, r - 1).index + 1 << endl;
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
