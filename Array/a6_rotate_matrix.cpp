#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void rotate(vector<vector<int>> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(v[i][j], v[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(v[i].begin(), v[i].end());
    }
}

int main()
{

    return 0;
}