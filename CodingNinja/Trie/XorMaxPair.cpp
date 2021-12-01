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
    TrieNode()
    {
        left = NULL;
        right = NULL;
    }
};

void insert(int arr[], int n, TrieNode *head)
{
    TrieNode *curr;
    for (int k = 0; k < n; k++)
    {
        curr = head;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (arr[k] >> i) & 1;
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
    }
}

void PrintMax(TrieNode *head)
{
    TrieNode *curr = head;
    int ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (curr->right != NULL)
        {
            // cout << 1 << " ";
            ans += pow(2, i);
            curr = curr->right;
        }
        else
        {
            // cout << 0 << " ";
            curr = curr->left;
        }
    }
    cout << ans << endl;
}
void PrintMin(TrieNode *head)
{
    TrieNode *curr = head;
    int ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (curr->left != NULL)
        {
            curr = curr->left;
        }
        else
        {
            ans += pow(2, i);
            curr = curr->right;
        }
    }
    cout << ans << endl;
}

int MaxXorPair(TrieNode *head, int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    int max_xor = INT_MIN;
    TrieNode *curr;
    for (int k = 0; k < n; k++)
    {
        curr = head;
        int curr_ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (arr[k] >> i) & 1;
            if (bit == 0)
            {
                if (curr->right != NULL)
                {
                    curr_ans += pow(2, i);
                    curr = curr->right;
                }
                else
                {
                    curr = curr->left;
                }
            }
            else
            {
                if (curr->left != NULL)
                {
                    curr_ans += pow(2, i);
                    curr = curr->left;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
        // max_xor = max(max_xor, curr_ans);
        if (curr_ans > max_xor)
        {
            // cout << arr[k] << " " << (arr[k] ^ max_xor) << " " << max_xor << endl;
            if (k == 0 && arr[k + 1] == (arr[k] ^ curr_ans))
            {
                max_xor = curr_ans;
            }
            else if (k == n - 1 && arr[k - 1] == (arr[k] ^ curr_ans))
            {
                max_xor = curr_ans;
            }
            else if (arr[k - 1] == (arr[k] ^ curr_ans) || arr[k + 1] == (arr[k] ^ curr_ans))
            {
                max_xor = curr_ans;
            }
        }
    }
    return max_xor;
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
    TrieNode *head = new TrieNode();
    insert(arr, n, head);
    cout << MaxXorPair(head, arr, 5) << endl;
    delete[] arr;
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
