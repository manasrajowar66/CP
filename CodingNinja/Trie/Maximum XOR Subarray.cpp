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
    int value;
    TrieNode()
    {
        left = NULL;
        right = NULL;
    }
};

void insert(TrieNode *head, int pre)
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
            }
            curr = curr->left;
        }
        else
        {
            if (curr->right == NULL)
            {
                curr->right = new TrieNode();
            }
            curr = curr->right;
        }
    }
    curr->value = pre;
}

int query(TrieNode *head, int pre)
{
    TrieNode *curr = head;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (pre >> i) & 1;
        if (bit == 0)
        {

            if (curr->right != NULL)
            {
                curr = curr->right;
            }
            else if (curr->left != NULL)
            {
                curr = curr->left;
            }
        }
        else
        {
            if (curr->left != NULL)
            {
                curr = curr->left;
            }
            else if (curr->right != NULL)
            {
                curr = curr->right;
            }
        }
    }
    return (curr->value ^ pre);
}

int MaxXorSubArray(int arr[], int n)
{
    TrieNode *head = new TrieNode();
    int pre = 0, ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        pre ^= arr[i];
        insert(head, pre);
        ans = max(ans, query(head, pre));
    }
    return ans;
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

    cout << MaxXorSubArray(arr, n) << endl;
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
