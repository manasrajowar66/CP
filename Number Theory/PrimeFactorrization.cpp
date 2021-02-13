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
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define Max 1000001

int is_prime[Max];
void seive()
{
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i < Max; i++)
    {
        is_prime[i] = -1;
    }

    for (int i = 2; i * i < Max; i++)
    {
        if (is_prime[i]==-1)
        {
            for (int j = i * i; j < Max; j += i)
            {
                if (is_prime[j]==-1)
                    is_prime[j] = i;
            }
        }
    }

   
}


void primeFactorization(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }
            cout << i << " " << cnt << endl;
        }
    }
    if (n > 1)
        cout << n << " " << 1 << endl;
}

// Prime Factoritiation using Seive

void seiveFactoritiation(int n){
    while(n>1){
      if(is_prime[n]==-1)
      {
          cout<<n;
          break;
      }else{
          cout<<is_prime[n]<<" ";
          n/=is_prime[n];
      }
    }
}

signed main()
{
    seive();
    int n;
    cin >> n;
    seiveFactoritiation(n);
    return 0;
}
