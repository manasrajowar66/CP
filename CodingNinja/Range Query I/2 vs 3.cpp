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
int power(int, int, int);
bool isPrime(int);

int power_of_two[100001];

void buildTree(string s, int *tree, int start, int end, int treeNode)
{
    if (start == end)
    {
        tree[treeNode] = (s[start] - '0');
        return;
    }
    int mid = (start + end) / 2;
    buildTree(s, tree, start, mid, treeNode * 2);
    buildTree(s, tree, mid + 1, end, treeNode * 2 + 1);
    tree[treeNode] = ((tree[treeNode * 2] * power_of_two[end - mid]) % 3 + tree[treeNode * 2 + 1]) % 3;
}

void updateTree(string s, int *tree, int start, int end, int treeNode, int update_ind)
{
    if (start == end)
    {
        if (start == update_ind && s[start] == '0')
        {
            s[start] = '1';
            tree[treeNode] = 1;
        }
        return;
    }
    int mid = (start + end) / 2;
    if (update_ind <= mid)
    {
        updateTree(s, tree, start, mid, treeNode * 2, update_ind);
    }
    else
    {
        updateTree(s, tree, mid + 1, end, (treeNode * 2) + 1, update_ind);
    }
    tree[treeNode] = ((tree[treeNode * 2] * power_of_two[end - mid]) % 3 + tree[treeNode * 2 + 1]) % 3;
}

int query(int *tree, int start, int end, int treeNode, int left, int right)
{
    if (start > right || end < left)
    {
        return -1;
    }

    if (start >= left && end <= right)
    {
        return tree[treeNode];
    }
    int mid = (start + end) / 2;
    int ans1 = query(tree, start, mid, treeNode * 2, left, right);
    int ans2 = query(tree, mid + 1, end, (treeNode * 2) + 1, left, right);
    if (ans1 == -1)
    {
        return ans2;
    }
    else if (ans2 == -1)
    {
        return ans1;
    }
    else
    {
        return ((ans1 * power_of_two[right - mid]) % 3 + ans2) % 3;
    }
}

signed main()
{
    int n;
    string s;
    int q;
    cin >> n >> s >> q;
    int *tree = new int[4 * n];
    power_of_two[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        power_of_two[i] = (power_of_two[i - 1] * 2) % 3;
    }
    buildTree(s, tree, 0, n - 1, 1);
    // for (int i = 1; i < 4 * n; i++)
    // {
    //     cout << tree[i] << endl;
    // }
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            int l, r;
            cin >> l >> r;
            cout << query(tree, 0, n - 1, 1, l, r) << endl;
        }
        else
        {
            int index;
            cin >> index;
            updateTree(s, tree, 0, n - 1, 1, index);
        }
    }
    delete[] tree;
    return 0;
}

// My Functions //

int power(int a, int n, int m)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res = (res % m * a % m) % m;
            n--;
        }
        else
        {
            a = (a % m * a % m) % m;
            n /= 2;
        }
    }
    return res % m;
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
