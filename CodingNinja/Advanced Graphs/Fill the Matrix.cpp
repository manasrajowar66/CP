#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
using namespace std;
bool bipartite(vector<int> edges[], map<int, map<int, int>> &m, int i, vector<int> &color)
{
    for (auto it : edges[i])
    {
        if (m[i][it] == 0)
        {
            if (color[it] == -1)
            {
                color[it] = color[i];
                if (!bipartite(edges, m, it, color))
                    return false;
            }
            else if (color[it] != color[i])
                return false;
        }
        else
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[i];
                if (!bipartite(edges, m, it, color))
                    return false;
            }
            else if (color[it] == color[i])
                return false;
        }
    }
    return true;
}
bool check(vector<int> edges[], map<int, map<int, int>> &m, int n)
{
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            if (!bipartite(edges, m, i, color))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        map<int, map<int, int>> m;
        vector<int> edges[n];
        bool ans = true;
        ;
        while (q--)
        {
            int i, j, v;
            cin >> i >> j >> v;
            i--;
            j--;
            edges[i].push_back(j);
            edges[j].push_back(i);
            if (m.find(i) != m.end() && m[i].find(j) != m[i].end())
            {
                if (m[i][j] != v)
                    ans = false;
            }
            else if (m.find(j) != m.end() && m[j].find(i) != m[j].end())
            {
                if (m[j][i] != v)
                    ans = false;
            }
            else
                m[i][j] = m[j][i] = v;
        }
        if (!ans)
        {
            cout << "no" << endl;
            continue;
        }
        ans = check(edges, m, n);
        if (ans)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}