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
    tci()
    {
        int n, k;
        cin >> n >> k;
        int *arr = new int[n];
        int *colors = new int[n + 1];
        map<int, int> hash;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (hash[arr[i]] < k)
            {
                hash[arr[i]]++;
            }
        }
        int no_of_colors = 0;
        for (auto v : hash)
        {
            no_of_colors += v.second;
        }
        int max_colors = no_of_colors / k;
        no_of_colors /= k;
        no_of_colors *= k;
        for (int i = 0; i < n; i++)
        {

            if (hash[arr[i]] > 0 && no_of_colors > 0)
            {
                cout << hash[arr[i]] << " ";
                hash[arr[i]]--;
                no_of_colors--;
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
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
