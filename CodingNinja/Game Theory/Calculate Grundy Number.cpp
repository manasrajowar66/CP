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
int grundyNumber[1000001];

void setGrundyNumbers()
{
    grundyNumber[0] = 0;
    grundyNumber[1] = 1;
    grundyNumber[2] = 2;
    grundyNumber[3] = 2;
    grundyNumber[4] = 3;
    grundyNumber[5] = 3;
    grundyNumber[6] = 0;
    for (int i = 7; i <= 1000000; i++)
    {
        if (grundyNumber[i / 2] != 0 && grundyNumber[i / 3] != 0 && grundyNumber[i / 6] != 0)
        {
            grundyNumber[i] = 0;
        }
        else if (grundyNumber[i / 2] != 1 && grundyNumber[i / 3] != 1 && grundyNumber[i / 6] != 1)
        {
            grundyNumber[i] = 1;
        }
        else if (grundyNumber[i / 2] != 2 && grundyNumber[i / 3] != 2 && grundyNumber[i / 6] != 2)
        {
            grundyNumber[i] = 2;
        }
        else
        {
            grundyNumber[i] = 3;
        }
    }
}

signed main()
{

    setGrundyNumbers();
    tci()
    {
        int n;
        cin >> n;
        cout << grundyNumber[n] << endl;
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
