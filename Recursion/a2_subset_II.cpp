#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans = {{}};
    sort(nums.begin(), nums.end());

    int i = 0;
    while (i < nums.size())
    {
        int j = upper_bound(nums.begin() + i, nums.end(), nums[i]) - nums.begin();
        int cnt = j - i;
        int m = ans.size();
        for (int k = 0; k < m; k++)
        {
            vector<int> curr = ans[k];
            for (int l = 0; l < cnt; l++)
            {
                curr.push_back(nums[i]);
                ans.push_back(curr);
                // ans.pop_back()
            }
        }
        i = j;
    }

    return ans;
}

int main()
{

    return 0;
}