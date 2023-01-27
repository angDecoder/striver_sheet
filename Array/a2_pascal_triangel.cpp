#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

vector<vector<int>> generate(int n)
{
    vector<vector<int>> p = {{1}};
    for (int i = 1; i < n; i++)
    {
        p.push_back({1});
        for (int j = 1; j < p[i - 1].size(); j++)
        {
            p[i].push_back(p[i - 1][j] + p[i - 1][j - 1]);
        }
        p[i].push_back(1);
    }

    return p;
}

int main()
{

    return 0;
}