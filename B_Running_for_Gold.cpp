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
class event
{
public:
    int value, index;
};

bool comp(event p1, event p2)
{
    return p1.value < p2.value;
}
signed main()
{
    tci()
    {
        int n;
        cin >> n;
        vector<vector<int>> temp(n);
        for (int i = 0; i < n; i++)
        {
            temp[i] = vector<int>(5);
            for (int j = 0; j < 5; j++)
            {
                int x;
                cin >> x;
                temp[i][j] = x;
            }
        }
        vector<vector<event>> arr(5);
        // for (int i = 0; i < 5; i++)
        // {
        //     arr[i] = new event[n];
        // }
        for (int i = 0; i < 5; i++)
        {
            arr[i] = vector<event>(n);
            for (int j = 0; j < n; j++)
            {
                arr[i][j].value = temp[j][i];
                arr[i][j].index = j;
            }
        }
        // if (n == 1)
        // {
        //     cout << 1 << endl;
        //     continue;
        // }
        for (int i = 0; i < 5; i++)
        {
            vector<event> dup;
            for (int j = 0; j < n; j++)
            {
                dup.push_back(arr[i][j]);
            }
            sort(dup.begin(), dup.end(), comp);
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = dup[j];
            }
        }
        // for (int i = 0; i < 5; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << arr[i][j].value << "," << arr[i][j].index << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // cout << endl;
        map<int, int> hash;
        for (int i = 0; i < 5; i++)
        {
            hash[arr[i][0].index]++;
        }
        int maxi = INT_MIN;
        int max_index;
        int max_value;
        int count = 0;
        for (auto x : hash)
        {
            if (maxi < x.second)
            {
                maxi = x.second;
                max_index = x.first;
            }
        }
        for (auto x : hash)
        {
            if (maxi == x.second)
            {
                count++;
            }
        }
        // for (int i = 0; i < 5; i++)
        // {
        //     if (max_value == arr[i][0].value)
        //     {
        //         max_index = arr[i][0].index + 1;
        //     }
        // }
        if (count == 1)
        {
            cout << max_index + 1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
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
