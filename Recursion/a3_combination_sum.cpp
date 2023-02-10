#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

vector<vector<int>> combinationSum(vector<int> &v, int t)
{
    vector<vector<vector<int>>> dp(t + 1);
    dp[0] = {{}};
    for (auto elem : v)
    {
        for (int i = 1; i <= t; i++)
        {
            if (i - elem < 0)
                continue;
            // vector<vector<int>> curr = ;
            for (auto temp : dp[i - elem])
            {
                temp.push_back(elem);
                dp[i].push_back(temp);
            }
        }
    }

    return dp[t];
}

void getComb(vector<int> &v, int t, int i, vector<vector<int>> &ans, vector<int> &curr)
{
    int n = v.size();
    if (i >= n or t < 0)
        return;
    if (t == 0)
    {
        ans.push_back(curr);
        return;
    }
    // if taken
    curr.push_back(v[i]);
    getComb(v, t - v[i], i, ans, curr);
    curr.pop_back();
    // not taken
    getComb(v, t, i + 1, ans, curr);
}

vector<vector<int>> combinationSum1(vector<int> &v, int t)
{
    // sort(v.begin(),v.end());
    vector<vector<int>> ans;
    vector<int> curr;
    getComb(v, t, 0, ans, curr);

    return ans;
}

int main()
{

    return 0;
}