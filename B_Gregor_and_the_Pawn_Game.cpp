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
        string s1, s2;
        int n, count = 0;
        cin >> n >> s1 >> s2;
        int *visited = new int[n];
        for (int i = 0; i < n; i++)
        {
            visited[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            if (s2[i] != '0' && s1[i] == '0' && !visited[i])
            {
                count++;
                visited[i] = 1;
            }
            else if (i > 0 && s2[i] != '0' && s1[i - 1] == '1' && !visited[i - 1])
            {
                count++;
                visited[i - 1] = 1;
            }
            else if (i < n - 1 && s2[i] != '0' && s1[i + 1] == '1' && !visited[i + 1])
            {
                count++;
                visited[i + 1] = 1;
            }
        }
        cout << count << endl;
        delete[] visited;
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
