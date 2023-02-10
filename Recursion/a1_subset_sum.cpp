#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

vector<int> subsetSum(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans = {0};
    for (int i = 0; i < n; i++)
    {
        int m = ans.size();
        for (int j = 0; j < m; j++)
        {
            ans.push_back(ans[j] + arr[i]);
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{

    return 0;
}