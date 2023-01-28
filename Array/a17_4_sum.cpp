#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void twoSum(vector<pair<int, int>> &v, vector<vector<int>> &ans, int i, long long t)
{
    int n = v.size();
    int j = n - 1;
    while (j > i)
    {
        int sum = v[i].first + v[j].first;
        if (sum == t)
        {
            ans.push_back({v[i].first, v[j].first});
            int curr = v[i].first;
            while (i < j and v[i].first == curr)
                i++;
            curr = v[j].first;
            while (j > i and v[j].first == curr)
                j--;
        }
        else if (sum < t)
            i++;
        else
            j--;
    }
}

void threeSum(vector<pair<int, int>> &v, vector<vector<int>> &ans, int i, long long t)
{
    int n = v.size();
    while (i < n)
    {
        int curr = v[i].first;

        vector<vector<int>> p;
        twoSum(v, p, i + 1, t - curr);

        for (auto &elem : p)
        {
            elem.push_back(curr);
            ans.push_back(elem);
        }

        while (i < n and v[i].first == curr)
            i++;
    }
}

vector<vector<int>> fourSum(vector<int> &nums, long long t)
{
    int n = nums.size();
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].first = nums[i];
        v[i].second = i;
    }
    vector<vector<int>> ans;
    sort(v.begin(), v.end());

    int i = 0;
    while (i < n)
    {
        int curr = v[i].first;

        vector<vector<int>> p;
        threeSum(v, p, i + 1, t - curr);

        for (auto &elem : p)
        {
            elem.push_back(curr);
            ans.push_back(elem);
        }

        while (i < n and v[i].first == curr)
            i++;
    }

    return ans;
}

int main()
{

    return 0;
}