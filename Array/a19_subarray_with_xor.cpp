#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int solve(vector<int> &v, int b)
{
    int n = v.size();
    int x = 0, ans = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    for (int i = 0; i < n; i++)
    {
        x = x ^ v[i];
        int toFind = x ^ b;
        if (m[toFind])
        {
            ans += m[toFind];
        }
        m[x]++;
    }

    return ans;
}

int main()
{

    return 0;
}