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

bool is_prime[Max];
int prefix[Max];

void seive()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < Max; i++)
    {
        is_prime[i] = true;
    }

    for (int i = 2; i * i < Max; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < Max; j += i)
            {
                if (is_prime[j])
                    is_prime[j] = false;
            }
        }
    }

    prefix[0] = prefix[1] = 0;

    for (int i = 2; i < Max; i++)
    {
        prefix[i] = prefix[i - 1];
        if (is_prime[i])
            prefix[i]++;
    }
}

signed main()
{
    seive();
    tci()
    {
        int n;
        cin >> n;
        cout << prefix[n] << endl;
    }
    return 0;
}
