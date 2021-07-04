#include <bits/stdc++.h>
using namespace std;
#define Mod 1000000007
#define int long long

signed main()
{

    // write your code here
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0;
        cin >> n;
        int hash[100001];
        memset(hash, 0, sizeof(hash));
        int arr[n];

        //Take Inputs
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            hash[arr[i]] = 1;
            // cout<<hash[arr[i]]<<" ";
        }
        // cout<<endl;
        sort(arr, arr + n);
        //Seive array
        for (int i = 0; i < n; i++)
        {
            for (int j = (arr[i] * 2); j < 100001; j += arr[i])
            {
                if (hash[j] > 0)
                {
                    hash[j] = (hash[j] + hash[arr[i]]) % Mod;
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     cout<<hash[arr[i]]<<" ";
        // }
        // cout<<endl;

        for (int i = 0; i < n; i++)
        {
            if (hash[arr[i]] > 0)
            {
                ans = (ans + hash[arr[i]]) % Mod;
            }
        }
        cout << ans << endl;
    }
    return 0;
}