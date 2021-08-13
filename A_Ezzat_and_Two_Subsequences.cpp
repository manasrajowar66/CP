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
        // std::cout << std::setprecision(9);
        int n;
        cin >> n;
        int *arr = new int[n];
        int maxi = INT_MIN;
        double count = 0, count2 = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            maxi = max(maxi, arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == maxi)
            {
                count++;
            }
            else
            {
                sum += arr[i];
                count2++;
            }
        }
        if (count >= 2)
        {
            sum += (maxi * (count - 1));
            count2 += (count - 1);
        }
        cout << fixed << setprecision(9) << (double)maxi + (sum / count2) << endl;
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
