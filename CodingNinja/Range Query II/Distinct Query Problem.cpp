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
    int ff, ss, index;
};

void update(int index, int value, int *BIT, int n)
{
    for (; index <= n; index += index & (-index))
    {
        BIT[index] += value;
    }
}
int value(int index, int *BIT)
{
    int count = 0;
    for (; index > 0; index -= index & (-index))
    {
        count += BIT[index];
    }
    return count;
}

bool comp(node p1, node p2)
{
    return p1.ss < p2.ss;
}

signed main()
{
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    node *query = new node[q];
    for (int i = 0; i < q; i++)
    {
        cin >> query[i].ff >> query[i].ss;
        query[i].index = i;
    }
    sort(query, query + q, comp);
    int *BIT = new int[n + 1]();
    int *ans = new int[q]();
    int total = 0, k = 0;
    map<int, int> hash;
    for (int i = 1; i <= n; i++)
    {
        if (hash[arr[i]] != 0)
        {
            update(hash[arr[i]], -1, BIT, n);
        }
        else
        {
            total++;
        }
        while (k < q && query[k].ss == i)
        {
            ans[query[k].index] = total - value(query[k].ff - 1, BIT);
            k++;
        }
        update(i, 1, BIT, n);
        hash[arr[i]] = i;
    }

    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }

    delete[] arr;
    delete[] query;
    delete[] BIT;
    delete[] ans;

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
