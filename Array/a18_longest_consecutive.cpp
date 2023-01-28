#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int longestConsecutive(vector<int> &v)
{
    int n = v.size();
    if (n == 0)
        return 0;
    int ans = 1;
    unordered_map<int, bool> m;
    for (int i = 0; i < n; i++)
        m[v[i]] = true;

    for (int i = 0; i < n; i++)
    {
        int curr1 = 1;
        int curr2 = 1;
        while (m[v[i] + curr1])
        {
            m[v[i] + curr1] = false;
            curr1++;
        }
        while (m[v[i] - curr2])
        {
            m[v[i] - curr2] = false;
            curr2++;
        }
        ans = max(ans, curr1 + curr2 - 1);
    }

    return ans;
}

int main()
{

    return 0;
}