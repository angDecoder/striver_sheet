#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void getPermute(int done, vector<vector<int>> &ans, vector<int> &curr, vector<bool> &vis, vector<int> &nums)
{
    int n = nums.size();
    if (done == n)
    {
        ans.push_back(curr);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            curr.push_back(nums[i]);
            getPermute(done + 1, ans, curr, vis, nums);
            vis[i] = false;
            curr.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> curr;
    vector<bool> vis(nums.size(), false);
    getPermute(0, ans, curr, vis, nums);
    return ans;
}

int main()
{

    return 0;
}