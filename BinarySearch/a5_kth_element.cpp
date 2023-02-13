#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int solve(vector<int> &row1, vector<int> &row2, int m, int n, int mid)
{
    int ans = 0;
    ans += upper_bound(row1.begin(), row1.end(), mid) - row1.begin();
    ans += upper_bound(row2.begin(), row2.end(), mid) - row2.begin();

    return ans;
}

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k)
{
    int start = 0, end = 1e6;
    while (end - start > 1)
    {
        int mid = start + (end - start) / 2;
        int res = solve(row1, row2, m, n, mid);

        if (res == k)
            end = mid;
        else if (res < k)
            start = mid + 1;
        else
            end = mid;
    }

    if (solve(row1, row2, m, n, start) >= k)
        return start;
    return end;
}

int main()
{

    return 0;
}