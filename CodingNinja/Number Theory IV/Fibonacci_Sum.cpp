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
bool isPrime(int);

void mul(int A[2][2], int B[2][2])
{
    int firstVal = ((A[0][0] * B[0][0]) % Mod + (A[0][1] * B[1][0]) % Mod) % Mod;
    int secondVal = ((A[0][0] * B[0][1]) % Mod + (A[0][1] * B[1][1]) % Mod) % Mod;
    int thirdVal = ((A[1][0] * B[0][0]) % Mod + (A[1][1] * B[1][0]) % Mod) % Mod;
    int fourthVal = ((A[1][0] * B[0][1]) % Mod + (A[1][1] * B[1][1]) % Mod) % Mod;

    A[0][0] = firstVal;
    A[0][1] = secondVal;
    A[1][0] = thirdVal;
    A[1][1] = fourthVal;
}

int power(int A[2][2], int n)
{
    int I[2][2] = {{1, 1}, {1, 0}};
    while (n > 0)
    {
        if (n & 1)
        {
            mul(I, A);
            n--;
        }
        else
        {
            mul(A, A);
            n /= 2;
        }
    }
    return I[0][0];
}

int fibo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int A[2][2] = {{1, 1}, {1, 0}};
    return power(A, n - 2);
}

signed main()
{
    tci()
    {
        int n, m;
        cin >> n >> m;
        cout << fibo(m + 2) - fibo(n + 1) << endl;
    }
    return 0;
}

// My Functions //

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
