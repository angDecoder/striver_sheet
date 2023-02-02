#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

vector<vector<int>> threeSum(vector<int> &v)
{
    sort(v.begin(), v.end());
    int n = v.size();
    vector<vector<int>> ans;
    int i = 0;
    while (i < n)
    {
        vector<vector<int>> curr = twoSum(v, -v[i], i + 1);
        for (auto &elem : curr)
        {
            elem.push_back(v[i]);
            ans.push_back(elem);
        }
        int elem = v[i];
        while (i < n and elem == v[i])
            i++;
    }

    return ans;
}

vector<vector<int>> twoSum(vector<int> &v, int t, int p)
{
    int n = v.size();
    int i = p, j = n - 1;
    vector<vector<int>> ans;
    while (j > i)
    {
        int sum = v[i] + v[j];
        if (sum == t)
        {
            ans.push_back({v[i], v[j]});
            int curr = v[i];
            while (i <= j and v[i] == curr)
                i++;
            curr = v[j];
            while (j >= i and v[j] == curr)
                j--;
        }
        else if (sum > t)
            j--;
        else
            i++;
    }

    return ans;
}

int main()
{

    return 0;
}