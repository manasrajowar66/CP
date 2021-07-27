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
    char type;
    int x;
};

int value(int *BIT, int index)
{
    int count = 0;
    for (; index > 0; index -= index & (-index))
    {
        count += BIT[index];
    }
    return count;
}

void update(int *BIT, int index, int n, int val)
{
    for (; index <= n; index += index & (-index))
    {
        BIT[index] += val;
    }
}

signed main()
{
    int q;
    cin >> q;
    node *query = new node[q];
    vector<int> arr;
    map<int, int> hash;
    for (int i = 0; i < q; i++)
    {
        cin >> query[i].type >> query[i].x;
        if (query[i].type == 'I' && hash[query[i].x] == 0)
        {
            arr.push_back(query[i].x);
            hash[query[i].x]++;
        }
    }
    sort(arr.begin(), arr.end());
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        hash[arr[i]] = i + 1;
    }
    // for (auto v : hash)
    // {
    //     cout << v.first << " " << v.second << endl;
    // }
    int *BIT = new int[size + 1]();
    for (int i = 0; i < q; i++)
    {
        if (query[i].type == 'I' && (value(BIT, hash[query[i].x]) == value(BIT, hash[query[i].x] - 1)))
        {
            update(BIT, hash[query[i].x], size, 1);
        }
        else if (query[i].type == 'D' && (value(BIT, hash[query[i].x]) != value(BIT, hash[query[i].x] - 1)))
        {
            update(BIT, hash[query[i].x], size, -1);
        }
        else if (query[i].type == 'K')
        {
            int low = 0, high = size - 1;
            int ans = -1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                int isAns = value(BIT, hash[arr[mid]]);
                if (isAns == query[i].x)
                {
                    ans = mid;
                    high = mid - 1;
                }
                else if (isAns < query[i].x)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            if (ans != -1)
            {
                cout << arr[ans] << endl;
            }
            else
            {
                cout << "invalid" << endl;
            }
        }
        else if (query[i].type == 'C')
        {
            int low = 0, high = size - 1;
            int ans = -1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (arr[mid] < query[i].x)
                {
                    ans = mid;
                    low = mid + 1;
                }
                else if (arr[mid] > query[i].x)
                {
                    high = mid - 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            if (ans != -1)
            {
                cout << value(BIT, hash[arr[ans]]) << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }
    delete[] query;
    delete[] BIT;
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
