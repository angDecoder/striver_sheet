#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int solve(vector<int> &v1, vector<int> &v2, int mid)
{
    int ans = 0;
    ans += upper_bound(v1.begin(), v1.end(), mid) - v1.begin();
    ans += upper_bound(v2.begin(), v2.end(), mid) - v2.begin();

    return ans;
}

double kthElement(vector<int> &v1, vector<int> &v2, int k)
{
    double start = -1e7, end = 1e7;

    while (end - start > 1)
    {
        int mid = start + (end - start) / 2;
        int res = solve(v1, v2, mid);

        if (res == k)
            end = mid;
        else if (res < k)
            start = mid + 1;
        else
            end = mid;
    }

    if (solve(v1, v2, start) >= k)
        return start;
    return end;
}

double findMedianSortedArrays(vector<int> &v1, vector<int> &v2)
{
    int n = v1.size(), m = v2.size();
    if ((n + m) % 2)
    {
        int k = (n + m) / 2 + 1;
        return kthElement(v1, v2, k);
    }
    else
    {
        int k1 = (n + m) / 2;
        int k2 = k1 + 1;

        return (kthElement(v1, v2, k1) + kthElement(v1, v2, k2)) / 2;
    }
}

int main()
{

    return 0;
}