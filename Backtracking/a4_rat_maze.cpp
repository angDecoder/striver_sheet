#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

bool isValid(int i, int j, vector<vector<int>> &v)
{
    int n = v.size(), m = v[0].size();
    return i >= 0 and j >= 0 and i < n and j < m and v[i][j] == 1;
}

void solve(int i, int j, vector<vector<int>> &v, vector<string> &ans, string curr)
{
    int n = v.size(), m = v[0].size();
    if (i == n - 1 and j == m - 1)
    {
        ans.push_back(curr);
        return;
    }

    // up
    if (isValid(i - 1, j, v))
    {
        v[i][j] = 0;
        solve(i - 1, j, v, ans, curr + "U");
        v[i][j] = 1;
    }
    // down
    if (isValid(i + 1, j, v))
    {
        v[i][j] = 0;
        solve(i + 1, j, v, ans, curr + "D");
        v[i][j] = 1;
    }

    // left
    if (isValid(i, j - 1, v))
    {
        v[i][j] = 0;
        solve(i, j - 1, v, ans, curr + "L");
        v[i][j] = 1;
    }

    // right
    if (isValid(i, j + 1, v))
    {
        v[i][j] = 0;
        solve(i, j + 1, v, ans, curr + "R");
        v[i][j] = 1;
    }
}

vector<string> findPath(vector<vector<int>> &v, int n)
{
    vector<string> ans;
    if (v[0][0] == 0)
        return ans;
    // string curr;
    solve(0, 0, v, ans, "");

    return ans;
}

int main()
{

    return 0;
}