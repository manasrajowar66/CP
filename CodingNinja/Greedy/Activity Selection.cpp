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
#define ff first
#define ss second
int power(int, int);
bool isPrime(int);

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.ss < p2.ss)
    {
        return true;
    }
    else if (p1.ss == p2.ss)
    {
        if (p1.ff > p2.ff)
        {
            return true;
        }
        else if (p1.ff == p2.ff)
        {
            return true;
        }
    }
    return false;
}

signed main()
{
    int n;
    cin >> n;
    pair<int, int> *arr = new pair<int, int>[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].ff;
        cin >> arr[i].ss;
    }
    sort(arr, arr + n, comp);
    int count = 1, last_selected_ind = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i].ff << " " << arr[i].ss << endl;
    // }
    // cout << "Ind Printing..." << endl;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].ff >= arr[last_selected_ind].ss)
        {
            // cout << last_selected_ind + 1 << " " << i + 1 << endl;
            last_selected_ind = i;
            count++;
        }
        // cout << arr[i].ff << " " << arr[i].ss << endl;
    }
    cout << count << endl;
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
