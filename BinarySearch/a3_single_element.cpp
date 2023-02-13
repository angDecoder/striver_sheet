#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int solve(vector<int> &v, int mid)
{
    int n = v.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] <= mid)
            ans++;
    }

    return ans;
}

int singleNonDuplicate(vector<int> &v)
{
    int n = v.size();
    int start = 0, end = 1e5 + 1;

    while (end - start > 1)
    {
        int mid = start + (end - start) / 2;
        int res = solve(v, mid);

        if (res % 2)
            end = mid;
        else
            start = mid + 1;
    }

    if (solve(v, start) % 2)
        return start;
    return end;
}

int main()
{

    return 0;
}