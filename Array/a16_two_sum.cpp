#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

vector<int> twoSum(vector<int> &nums, int t)
{
    int n = nums.size();
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].second = i;
        v[i].first = nums[i];
    }
    int i = 0, j = n - 1;
    sort(v.begin(), v.end());

    while (j > i)
    {
        int sum = v[i].first + v[j].first;
        if (sum == t)
            return {v[i].second, v[j].second};
        if (sum > t)
            j--;
        else
            i++;
    }

    return {-1, -1};
}

int main()
{

    return 0;
}