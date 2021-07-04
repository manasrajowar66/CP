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
int dp[1000001][1000001];
int solve(int n, int e, int h, int a, int b, int c)
{
    int price = INT_MAX,int fl=1;
    if(2*n<=e){
       price = min(price,n*a);
    }
    if(3*n<=h){
        price = min(price,n*b);
    }
    if(n<=e && n<=h){
        price = min(price,n*c);
    }
    if(e/2>=1 && )
}

signed main()
{
    tci()
    {
        int n, e, h, a, b, c;
        cin >> n >> e >> h >> a >> b >> c;
        cout<<solve(n,e,h,a,b,c)<<endl;
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
