#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int solve(vector<int> &v, int page)
{
    int ans = 0;
    long long curr = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        curr += v[i];
        if (curr > page)
            ans++, curr = v[i];
        else if (curr == page)
            ans++, curr = 0;
    }
    if (curr > 0)
        ans++;

    return ans;
}

int books(vector<int> &v, int s)
{
    int n = v.size();
    if (s > n)
        return -1;
    long long start = 0, end = 0;
    for (int i = 0; i < n; i++)
    {
        start = max(start, (long long)v[i]);
        end += v[i];
    }

    while (end - start > 1)
    {
        long long mid = start + (end - start) / 2;
        long long res = solve(v, mid);

        if (res == s)
            end = mid;
        else if (res > s)
            start = mid + 1;
        else
            end = mid;
    }

    if (solve(v, start) <= s)
        return start;
    if (solve(v, end) <= s)
        return end;

    return -1;
}

int main()
{

    return 0;
}