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
#define ff first
#define ss second
int power(int, int);
bool isPrime(int);

struct Node
{
    int maxSum;
    int sum;
    int best_prefix_sum;
    int best_suffix_sum;
};

void buildTree(int *arr, Node *tree, int start, int end, int treeNode)
{
    if (start == end)
    {
        tree[treeNode].maxSum = arr[start];
        tree[treeNode].sum = arr[start];
        tree[treeNode].best_prefix_sum = arr[start];
        tree[treeNode].best_suffix_sum = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);
    int LS = tree[treeNode * 2].sum;
    int RS = tree[treeNode * 2 + 1].sum;
    int LBPS = tree[treeNode * 2].best_prefix_sum;
    int LBSS = tree[treeNode * 2].best_suffix_sum;
    int RBPS = tree[treeNode * 2 + 1].best_prefix_sum;
    int RBSS = tree[treeNode * 2 + 1].best_suffix_sum;
    int LMS = tree[treeNode * 2].maxSum;
    int RMS = tree[treeNode * 2 + 1].maxSum;
    tree[treeNode].maxSum = max(LMS, max(RMS, LS + RBPS));
    tree[treeNode].maxSum = max(tree[treeNode].maxSum, max(RS + LBSS, LBSS + RBPS));
    tree[treeNode].sum = LS + RS;
    tree[treeNode].best_prefix_sum = max(LBPS, LS + RBPS);
    tree[treeNode].best_suffix_sum = max(RBSS, RS + LBSS);
}

Node query(Node *tree, int start, int end, int treeNode, int left, int right)
{

    //completely outside
    if (start > right || end < left)
    {
        Node temp;
        temp.maxSum = INT_MIN;
        temp.sum = INT_MIN;
        temp.best_suffix_sum = INT_MIN;
        temp.best_prefix_sum = INT_MIN;
        return temp;
    }
    //completely inside
    if (start >= left && end <= right)
    {
        return tree[treeNode];
    }
    //partialy inside
    int mid = (start + end) / 2;
    Node leftAns = query(tree, start, mid, treeNode * 2, left, right);
    Node rightAns = query(tree, mid + 1, end, treeNode * 2 + 1, left, right);
    int LS = leftAns.sum;
    int RS = rightAns.sum;
    int LBPS = leftAns.best_prefix_sum;
    int LBSS = leftAns.best_suffix_sum;
    int RBPS = rightAns.best_prefix_sum;
    int RBSS = rightAns.best_suffix_sum;
    int LMS = leftAns.maxSum;
    int RMS = rightAns.maxSum;
    Node temp;
    temp.maxSum = max(LMS, max(RMS, LS + RBPS));
    temp.maxSum = max(temp.maxSum, max(RS + LBSS, LBSS + RBPS));
    temp.sum = LS + RS;
    temp.best_prefix_sum = max(LBPS, LS + RBPS);
    temp.best_suffix_sum = max(RBSS, RS + LBSS);
    return temp;
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

    Node *tree = new Node[4 * n];
    buildTree(arr, tree, 0, n - 1, 1);
    // for (int i = 1; i < 2 * n; i++)
    // {
    //     cout << tree[i] << " ";
    // }
    // cout << endl;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(tree, 0, n - 1, 1, l - 1, r - 1).maxSum << endl;
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
