#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int maxSubArray(vector<int> &v)
{
    int n = v.size();
    int ans = v[0];
    int curr = v[0];
    for (int i = 1; i < n; i++)
    {
        curr+=v[i];
        curr = max(curr,v[i]);
        ans = max(curr, ans);
    }

    return ans;
}

int main()
{

    return 0;
}