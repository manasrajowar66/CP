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

struct lazyStruct
{
    int type;
    int value;
};

struct treeStruct
{
    int sum_of_square;
    int sum;
};

void buildTree(int *arr, treeStruct *tree, int start, int end, int treeNode)
{
    if (start == end)
    {
        tree[treeNode].sum = arr[start];
        tree[treeNode].sum_of_square = arr[start] * arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);
    tree[treeNode].sum = tree[treeNode * 2].sum + tree[treeNode * 2 + 1].sum;
    tree[treeNode].sum_of_square = tree[treeNode * 2].sum_of_square + tree[treeNode * 2 + 1].sum_of_square;
}

void updateTree(treeStruct *tree, lazyStruct *lazy, int start, int end, int treeNode, int type, int startR, int endR, int inc_value)
{
    if (start > end)
    {
        return;
    }

    if (lazy[treeNode].type != 0)
    {

        if (lazy[treeNode].type == 1)
        {
            int value = lazy[treeNode].value;
            int sum = tree[treeNode].sum;
            tree[treeNode].sum_of_square += (2 * value * sum + value * value * (end - start + 1));
            tree[treeNode].sum += (value * (end - start + 1));
            if (start != end)
            {
                lazy[treeNode * 2].value += value;
                lazy[treeNode * 2].type = 1;
                lazy[treeNode * 2 + 1].value += value;
                lazy[treeNode * 2 + 1].type = 1;
            }
        }
        else if (lazy[treeNode].type == 2)
        {
            int value = lazy[treeNode].value;
            int sum = tree[treeNode].sum;
            tree[treeNode].sum_of_square = (value * value * (end - start + 1));
            tree[treeNode].sum = (value * (end - start + 1));
            if (start != end)
            {
                lazy[treeNode * 2].value = value;
                lazy[treeNode * 2].type = 2;
                lazy[treeNode * 2 + 1].value = value;
                lazy[treeNode * 2 + 1].type = 2;
            }
        }

        lazy[treeNode].type = 0;
        lazy[treeNode].value = 0;
    }

    if (start > endR || end < startR)
    {
        return;
    }

    if (start >= startR && end <= endR)
    {
        if (type == 0)
        {
            tree[treeNode].sum_of_square = (inc_value * inc_value * (end - start + 1));
            tree[treeNode].sum = (inc_value * (end - start + 1));
            if (start != end)
            {
                lazy[treeNode * 2].value = inc_value;
                lazy[treeNode * 2].type = 2;
                lazy[treeNode * 2 + 1].value = inc_value;
                lazy[treeNode * 2 + 1].type = 2;
            }
        }
        else if (type == 1)
        {
            tree[treeNode].sum_of_square += (2 * inc_value * tree[treeNode].sum + inc_value * inc_value * (end - start + 1));
            tree[treeNode].sum += (inc_value * (end - start + 1));
            if (start != end)
            {
                lazy[treeNode * 2].value += inc_value;
                lazy[treeNode * 2].type = 1;
                lazy[treeNode * 2 + 1].value += inc_value;
                lazy[treeNode * 2 + 1].type = 1;
            }
        }
        return;
    }

    int mid = (start + end) / 2;

    updateTree(tree, lazy, start, mid, 2 * treeNode, type, startR, endR, inc_value);
    updateTree(tree, lazy, mid + 1, end, 2 * treeNode + 1, type, startR, endR, inc_value);

    tree[treeNode].sum = tree[treeNode * 2].sum + tree[treeNode * 2 + 1].sum;
    tree[treeNode].sum_of_square = tree[treeNode * 2].sum_of_square + tree[treeNode * 2 + 1].sum_of_square;
}

treeStruct query(treeStruct *tree, lazyStruct *lazy, int start, int end, int treeNode, int left, int right)
{

    if (start > end)
    {
        treeStruct temp;
        temp.sum_of_square = 0;
        temp.sum = 0;
        return temp;
    }

    if (lazy[treeNode].type != 0)
    {
        if (lazy[treeNode].type == 1)
        {
            int value = lazy[treeNode].value;
            int sum = tree[treeNode].sum;
            tree[treeNode].sum_of_square += (2 * value * sum + value * value * (end - start + 1));
            tree[treeNode].sum += (value * (end - start + 1));
            if (start != end)
            {
                lazy[treeNode * 2].value += value;
                lazy[treeNode * 2].type = 1;
                lazy[treeNode * 2 + 1].value += value;
                lazy[treeNode * 2 + 1].type = 1;
            }
        }
        else if (lazy[treeNode].type == 2)
        {
            int value = lazy[treeNode].value;
            int sum = tree[treeNode].sum;
            tree[treeNode].sum_of_square = (value * value * (end - start + 1));
            tree[treeNode].sum = (value * (end - start + 1));
            if (start != end)
            {
                lazy[treeNode * 2].value = value;
                lazy[treeNode * 2].type = 2;
                lazy[treeNode * 2 + 1].value = value;
                lazy[treeNode * 2 + 1].type = 2;
            }
        }

        lazy[treeNode].type = 0;
    }

    //completely outside
    if (start > right || end < left)
    {
        treeStruct temp;
        temp.sum_of_square = 0;
        temp.sum = 0;
        return temp;
    }
    //completely inside
    if (start >= left && end <= right)
    {
        return tree[treeNode];
    }
    //partialy inside
    int mid = (start + end) / 2;
    treeStruct ans1 = query(tree, lazy, start, mid, treeNode * 2, left, right);
    treeStruct ans2 = query(tree, lazy, mid + 1, end, treeNode * 2 + 1, left, right);
    treeStruct ans;
    ans.sum = (ans1.sum + ans2.sum);
    ans.sum_of_square = (ans1.sum_of_square + ans2.sum_of_square);
    return ans;
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
    tci()
    {
        int n, q;
        cin >> n >> q;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        treeStruct *tree = new treeStruct[2 * n];
        lazyStruct *lazy = new lazyStruct[2 * n];
        memset(lazy, 0, sizeof(lazy));

        for (int i = 1; i < 2 * n; i++)
        {
            lazy[i].type = 0;
            lazy[i].value = 0;
        }

        buildTree(arr, tree, 0, n - 1, 1);

        while (q--)
        {
            int type;
            cin >> type;
            if (type == 2)
            {
                int l, r;
                cin >> l >> r;
                cout << query(tree, lazy, 0, n - 1, 1, l - 1, r - 1).sum_of_square << endl;
            }
            else
            {
                int l, r, value;
                cin >> l >> r >> value;
                updateTree(tree, lazy, 0, n - 1, 1, type, l - 1, r - 1, value);
            }
        }
        delete[] arr;
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
