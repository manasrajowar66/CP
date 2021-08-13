#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    string s;
    cin >> s;
    int *arr = new int[10]();
    for (int i = 0; i < s.length(); i++)
    {
        arr[s[i] - '0'] = 1;
    }
    int firstMaxi = INT_MIN, secondMaxi = INT_MIN;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == 1)
        {
            firstMaxi = max(firstMaxi, i);
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == 1 && firstMaxi != i)
        {
            secondMaxi = max(secondMaxi, i);
        }
    }
    cout << firstMaxi * 10 + secondMaxi << endl;
    delete[] arr;
    return 0;
}
