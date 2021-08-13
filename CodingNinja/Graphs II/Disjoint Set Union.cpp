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

class DSNode
{
public:
    int data;
    DSNode *parent;
    int rank;
};

class DisjointSet
{
private:
    map<int, DSNode *> hash;
    DSNode *findParentNode(DSNode *node)
    {
        if (node == node->parent)
        {
            return node;
        }
        node->parent = findParentNode(node->parent);
        return node->parent;
    }

public:
    void initialize(int data)
    {
        DSNode *node = new DSNode();
        node->data = data;
        node->parent = node;
        node->rank = 0;
        hash[data] = node;
    }
    void Union(int data1, int data2)
    {
        DSNode *node1 = hash[data1];
        DSNode *node2 = hash[data2];
        DSNode *parent1 = findParentNode(node1);
        DSNode *parent2 = findParentNode(node2);
        if (parent1 == parent2)
        {
            return;
        }
        if (parent1->rank >= parent2->rank)
        {
            if (parent2->rank == parent1->rank)
            {
                parent1->rank = parent1->rank + 1;
            }
            parent2->parent = parent1;
        }
    }
    int searchInSet(int data)
    {
        return findParentNode(hash[data])->data;
    }
};

signed main()
{
    DisjointSet ds;

    ds.initialize(0);
    ds.initialize(1);
    ds.initialize(2);
    ds.initialize(3);
    ds.initialize(4);
    ds.initialize(5);
    ds.initialize(6);

    ds.Union(0, 1);
    ds.Union(1, 2);
    ds.Union(3, 4);
    ds.Union(2, 4);
    ds.Union(5, 6);
    ds.Union(4, 6);

    cout << ds.searchInSet(0) << endl;
    cout << ds.searchInSet(1) << endl;
    cout << ds.searchInSet(2) << endl;
    cout << ds.searchInSet(3) << endl;
    cout << ds.searchInSet(4) << endl;
    cout << ds.searchInSet(5) << endl;
    cout << ds.searchInSet(6) << endl;

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
