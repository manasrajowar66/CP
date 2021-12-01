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

signed main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && (st.top() > arr[i]) && ((n - i + st.size() - 1) >= k))
        {
            // cout << st.top() << " " << arr[i] << endl;
            st.pop();
        }
        if (st.size() < k)
        {
            st.push(arr[i]);
        }
    }
    int dig_number = 0, ans = 0;
    while (!st.empty())
    {
        cout << st.top() << endl;
        ans += (st.top() * pow(10, dig_number));
        dig_number++;
        st.pop();
    }
    cout << ans;
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
