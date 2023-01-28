#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int atMost(vector<int> &v, int k)
{
    int n = v.size();
    int i = 0;
    int dist = 0;
    int N = 2 * 1e4 + 7;
    vector<int> f(N, 0);
    int ans = 0;
    for (int j = 0; j < n; j++)
    {
        f[v[j]]++;
        if (f[v[j]] == 1)
            dist++;
        while (i <= j and dist > k)
        {
            f[v[i]]--;
            if (f[v[i]] == 0)
                dist--;
            i++;
        }

        ans += j - i + 1;
    }

    return ans;
}

int subarraysWithKDistinct(vector<int> &v, int k)
{
    return atMost(v, k) - atMost(v, k - 1);
}

int main()
{

    return 0;
}