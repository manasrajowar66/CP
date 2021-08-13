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
    int index, val;
};

bool comp(node p1, node p2)
{
    return p1.val < p2.val;
}

signed main()
{
    tci()
    {
        int n, k;
        cin >> n >> k;
        node *arr = new node[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].val;
            arr[i].index = i;
        }
        sort(arr, arr + n, comp);
        int increasingCount = 1, count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if ((arr[i].index + 1) == arr[i + 1].index)
            {
                increasingCount++;
                // cout << arr[i].index << " " << arr[i + 1].index << endl;
            }
            else
            {
                // cout << count++ << endl;
                count++;
                increasingCount = 1;
            }
        }
        if (n >= 2 && ((arr[n - 2].index + 1) != arr[n - 1].index))
        {
            count++;
            // cout << count++ << endl;
            // cout << arr[n - 2].index << " " << arr[n - 1].index << endl;
        }
        if (n >= 2 && ((arr[0].index + 1) != arr[1].index))
        {
            count++;
            // cout << count++ << endl;
            // cout << arr[n - 2].index << " " << arr[n - 1].index << endl;
        }
        if (count <= k)
        {
            cout << "Yes" << count << endl;
        }
        else
        {
            cout << "No" << count << endl;
        }
        delete[] arr;
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
