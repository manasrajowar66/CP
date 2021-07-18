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

bool check_factors(vector<pair<int, int>> vp, vector<pair<int, int>> vq)
{
    for (int i = 0; i < vp.size(); i++)
    {
        if (vq[i].second < vp[i].second)
        {
            return false;
        }
    }
    return true;
}

void add_factors(vector<pair<int, int>> &vq, int n)
{
    for (int i = 0; i < vq.size(); i++)
    {
        int prime = vq[i].first, count = 0;
        while (n % prime == 0)
        {
            count++;
            n /= prime;
        }
        vq[i].second += count;
        // cout << vq[i].first << " " << vq[i].second << "|";
    }
    // cout << endl;
}

void remove_factors(vector<pair<int, int>> &vq, int n)
{
    for (int i = 0; i < vq.size(); i++)
    {
        int prime = vq[i].first, count = 0;
        while (n % prime == 0)
        {
            count++;
            n /= prime;
        }
        vq[i].second -= count;
        // cout << vq[i].first << " " << vq[i].second << "|";
    }
    // cout << endl;
}

signed main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<pair<int, int>> vp;
    vector<pair<int, int>> vq;
    int temp = k;
    for (int i = 2; i * i <= temp; i++)
    {
        if (temp % i == 0)
        {
            int count = 0;
            while (temp % i == 0)
            {
                count++;
                temp /= i;
            }
            vp.push_back({i, count});
            vq.push_back({i, 0});
        }
    }
    if (temp > 1)
    {
        vp.push_back({temp, 1});
        vq.push_back({temp, 0});
    }

    int i = 0, j = 0;
    int ans = 0;
    while (j < n || i < n)
    {

        if (check_factors(vp, vq))
        {
            ans += (n - i + 1);
            if (j < n)
            {
                remove_factors(vq, arr[j]);
            }
            j++;
        }
        else
        {
            bool check = true;
            if (i < n)
            {
                add_factors(vq, arr[i]);
                check = false;
            }
            i++;
            if (i >= n && j < n && check)
            {
                j++;
            }
        }
    }

    cout << ans;

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
