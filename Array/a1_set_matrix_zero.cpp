#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int


// set first elem of col and row to zero 
// also save if there exist zero orignally
void setZeroes(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();
    bool row = false;
    bool col = false;
    for (int i = 0; i < n; i++)
    {
        if (v[i][0] == 0)
            col = true;
    }
    for (int j = 0; j < m; j++)
    {
        if (v[0][j] == 0)
            row = true;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][j] == 0)
                v[i][0] = 0, v[0][j] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][0] == 0 or v[0][j] == 0)
                v[i][j] = 0;
        }
    }

    if (row == true)
    {
        for (int j = 0; j < m; j++)
        {
            v[0][j] = 0;
        }
    }

    if (col)
    {
        for (int i = 0; i < n; i++)
        {
            v[i][0] = 0;
        }
    }
}

int main()
{

    return 0;
}