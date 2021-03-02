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

// Initilize Struct Node
struct Node
{
    Node *left = NULL;
    Node *right = NULL;
    int key = 0;
    Node(int data)
    {
        key = data;
    }
};

// Inorder Traversal
void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

// Preorder Traversal
void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->key << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Traversal in Spiral Form
void spiralForm(Node *root)
{
    vector<Node *> arr;
    arr.push_back(root);
    int fl = 1;
    while (arr.size() != 0)
    {
        int len = arr.size();
        if (fl)
        {
            for (int i = 0; i < len; i++)
            {
                Node *temp = arr[i];
                cout << temp->key << " ";
                if (temp->left != NULL)
                    arr.push_back(temp->left);
                if (temp->right != NULL)
                    arr.push_back(temp->right);
            }
            arr.erase(arr.begin(), arr.begin() + len);
            fl = !fl;
        }
        else
        {
            for (int i = 0; i < len; i++)
            {
                Node *temp = arr[i];
                if (temp->left != NULL)
                    arr.push_back(temp->left);
                if (temp->right != NULL)
                    arr.push_back(temp->right);
            }
            for (int i = len - 1; i >= 0; i--)
            {
                Node *temp = arr[i];
                cout << temp->key << " ";
            }
            arr.erase(arr.begin(), arr.begin() + len);
            fl = !fl;
        }
    }
}

// height hash table
map<Node *, int> height;
int heightBT(Node *root)
{
    if (root == NULL)
        return 0;
    height[root] = 1 + max(heightBT(root->left), heightBT(root->right));
    return height[root];
}

// diameter calcuation
int diameter = 0;
int diameterBT(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = diameterBT(root->left);
    int rh = diameterBT(root->right);
    diameter = max(1 + lh + rh, diameter);
    return 1 + max(lh, rh);
}

//Construct a BT
int preInd = 0;
Node *cTree(int in[], int pre[], int start, int end)
{
    if (start > end)
        return NULL;

    Node *root = new Node(pre[preInd++]);

    int inInd;
    for (int i = start; i <= end; i++)
    {
        if (in[i] == root->key)
        {
            inInd = i;
            break;
        }
    }

    root->left = cTree(in, pre, start, inInd - 1);
    root->right = cTree(in, pre, inInd + 1, end);
    return root;
}

signed main()
{
    int in[8] = {20, 10, 60, 40, 70, 30, 50, 80};
    int pre[8] = {10, 20, 30, 40, 60, 70, 50, 80};
    int len = sizeof(in) / sizeof(in[0]);
    Node *root = cTree(in, pre, 0, len - 1);
    diameterBT(root);
    cout << diameter;
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
