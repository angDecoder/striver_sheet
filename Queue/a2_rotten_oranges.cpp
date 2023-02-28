#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

vector<vector<int>> pos = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool isValid(int i, int j, vector<vector<int>> &g)
{
    int n = g.size(), m = g[0].size();
    return i >= 0 and j >= 0 and i < n and j < m and g[i][j] == 1;
}

int orangesRotting(vector<vector<int>> &g)
{
    int n = g.size(), m = g[0].size();

    queue<vector<int>> q;
    int cover = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 2)
                q.push({i, j, 0});

            if (g[i][j] != 1)
                cover++;
        }
    }
    int ans = 0;
    while (!q.empty())
    {
        vector<int> curr = q.front();
        q.pop();
        for (auto elem : pos)
        {
            int i = elem[0] + curr[0];
            int j = elem[1] + curr[1];
            if (!isValid(i, j, g))
                continue;
            cover++;
            g[i][j] = 2;
            q.push({i, j, curr[2] + 1});
        }

        ans = max(ans, curr[2]);
    }

    if (cover == n * m)
        return ans;
    return -1;
}

int main()
{

    return 0;
}