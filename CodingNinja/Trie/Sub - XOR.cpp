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

class TrieNode
{
public:
    TrieNode *left;
    TrieNode *right;
    TrieNode *parent;
    int leaf;
    int value;
    TrieNode()
    {
        left = NULL;
        right = NULL;
        parent = NULL;
        leaf = 1;
    }
};

TrieNode *insert(TrieNode *head, int pre)
{
    TrieNode *curr = head;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (pre >> i) & 1;
        if (bit == 0)
        {
            if (curr->left == NULL)
            {
                curr->left = new TrieNode();
                (curr->left)->parent = curr;
            }
            curr = curr->left;
        }
        else
        {
            if (curr->right == NULL)
            {
                curr->right = new TrieNode();
                (curr->right)->parent = curr;
            }
            curr = curr->right;
        }
    }
    curr->value = pre;
    return curr;
}

int query(TrieNode *head, int pre, int k)
{
    TrieNode *curr = head;
    int ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        int bitPre = (pre >> i) & 1;
        int bitK = (k >> i) & 1;
        if (curr == NULL)
        {
            break;
        }
        if (bitK == 1 && bitPre == 1)
        {

            if (curr->right != NULL)
            {
                ans += curr->right->leaf;
            }
            curr = curr->left;
        }
        else if (bitPre == 1 && bitK == 0)
        {
            if (curr->right != NULL)
            {
                curr = curr->right;
            }
            else
            {
                break;
            }
        }
        else if (bitPre == 0 && bitK == 1)
        {
            if (curr->left != NULL)
            {
                ans += curr->left->leaf;
            }
            curr = curr->right;
        }
        else if (bitPre == 0 && bitK == 0)
        {
            if (curr->left != NULL)
            {
                curr = curr->left;
            }
            else
            {
                break;
            }
        }
    }
    return ans;
}

void update(TrieNode *head)
{
    if (head->left != NULL && head->right != NULL)
    {
        head->leaf = (head->left)->leaf + (head->right)->leaf;
    }
    else if (head->left != NULL)
    {
        head->leaf = (head->left)->leaf;
    }
    else if (head->right != NULL)
    {
        head->leaf = (head->right)->leaf;
    }
    if (head->parent != NULL)
    {
        update(head->parent);
    }
}

int MaxXorSubArray(int arr[], int n, int k)
{
    TrieNode *head = new TrieNode();
    int pre = 0, ans = 0;
    TrieNode *leafNode = insert(head, 0);
    for (int i = 0; i < n; i++)
    {
        pre ^= arr[i];

        ans += query(head, pre, k);
        leafNode = insert(head, pre);
        update(leafNode);

        // ans = max(ans, query(head, pre));
    }

    return ans;
}

signed main()
{
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << MaxXorSubArray(arr, n, k) << endl;
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
