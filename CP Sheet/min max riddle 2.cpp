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

int *solve(int *arr, int n)
{
    int *ans = new int[n + 1]();
    int *right = new int[n];
    int *left = new int[n];
    stack<int> st;

    for (int i = 0; i < n; ++i)
    {
        left[i] = -1;
        while (!st.empty() && arr[i] <= arr[st.top()])
        {
            st.pop();
        }
        if (!st.empty())
        {
            left[i] = st.top();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        st.pop();
    }

    for (int i = n - 1; i >= 0; --i)
    {
        right[i] = n;
        while (!st.empty() && arr[i] <= arr[st.top()])
        {
            st.pop();
        }
        if (!st.empty())
        {
            right[i] = st.top();
        }
        st.push(i);
    }

    for (int i = 0; i < n; ++i)
    {
        int len = right[i] - left[i] - 1;
        ans[len] = max(ans[len], arr[i]);
    }
    for (int i = n - 1; i >= 1; --i)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    delete[] right;
    delete[] left;
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
    int *ans = solve(arr, n);
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << " ";
    }
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
