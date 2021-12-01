//https://www.hackerrank.com/challenges/min-max-riddle/problem

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

int maxOfKWin(vector<int> arr, int n, int k)
{
    deque<int> dq(k);
    int maxi = INT_MIN;
    int i;
    for (i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[i] <= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (; i < n; i++)
    {
        // cout << arr[dq.front()] << " ";
        maxi = max(maxi, arr[dq.front()]);

        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && arr[i] <= arr[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }
    // cout << arr[dq.front()] << " ";
    maxi = max(maxi, arr[dq.front()]);
    return maxi;
}

vector<int> solve(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        int x = maxOfKWin(arr, n, i);
        ans.push_back(x);
    }
    return ans;
}

signed main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    vector<int> ans = solve(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
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
