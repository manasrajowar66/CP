#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lli long long int
#define ll long long
#define vec vector<int>
#define for0() for (int i = 0; i < n; i++)
#define for1() for (int i = 1; i <= n; i++)
#define backloop() for (int i = n - 1; i >= 0; i--)
#define ff first
#define ss second
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

int lps(string s)
{
    int len = s.length();
    vec arr(len);
    arr[0] = 0;
    int i = 0, j = 1;
    while (j < len)
    {
        if (s[i] == s[j])
        {
            arr[j] = i + 1;
            j++;
            i++;
        }
        else
        {
            if (i == 0)
            {
                arr[j] = 0;
                j++;
            }
            else
            {
                i = arr[i - 1];
            }
        }
    }
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return arr[len - 1] > len / 2 ? len / 2 : arr[len - 1];
}

signed main()
{
    string s;
    cin >> s;
    cout << lps(s);
    return 0;
}
