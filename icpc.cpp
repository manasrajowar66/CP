#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int max_path;
void dfs(vector<int> *edges, int *visited, int sv, int *firstBenchers, int path)
{
    if (firstBenchers[sv])
        return;
    max_path = max(path, max_path);
    visited[sv] = 1;
    for (int i = 0; i < edges[sv].size(); i++)
    {
        int next = edges[sv][i];
        if (!visited[next] && !firstBenchers[next])
        {
            dfs(edges, visited, next, firstBenchers, path + 1);
        }
    }
}
int GetJumpCount(int input1, int input2, int input3, int input4[])
{
    int total_jumps = 0;
    for (int i = 0; i < input3; i++)
    {
        int temp = (input4[i] % input1 + ((input4[i] / input1)) * input2);
        total_jumps += input4[i] / input1 + temp / input1 + ((temp % input1) ? 1 : 0);
    }
    return total_jumps;
}

int main()
{
    int n = 4;
    cout << (n);
}
