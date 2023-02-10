#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void getComb(vector<int> &v, int t, int i, vector<vector<int>> &ans, vector<int> &curr)
{
    int n = v.size();
    if (t == 0)
    {
        ans.push_back(curr);
        return;
    }
    if (i >= n or t < 0)
        return;

    // if taken
    curr.push_back(v[i]);
    getComb(v, t - v[i], i + 1, ans, curr);
    curr.pop_back();
    // if not taken
    int j = i;
    while (j < n and v[i] == v[j])
        j++;
    getComb(v, t, j, ans, curr);
}

vector<vector<int>> combinationSum2(vector<int> &v, int t)
{
    sort(v.begin(), v.end());
    vector<vector<int>> ans;
    vector<int> curr;
    getComb(v, t, 0, ans, curr);
    return ans;
}

int main()
{

    return 0;
}