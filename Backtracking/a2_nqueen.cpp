#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

bool isValid(int i, int j, vector<string> &curr)
{
    int p = i, q = j;
    while (p >= 0)
    {
        if (curr[p][q] == 'Q')
            return false;

        p--;
    }
    p = i, q = j;
    while (p >= 0 and q >= 0)
    {
        if (curr[p][q] == 'Q')
            return false;
        p--, q--;
    }
    p = i, q = j;
    while (p >= 0 and q >= 0)
    {
        if (curr[p][q] == 'Q')
            return false;
        p--, q++;
    }

    return true;
}

void nqueen(int i, vector<vector<string>> &ans, vector<string> &curr)
{
    int n = curr.size();
    if (i == n)
    {
        ans.push_back(curr);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (!isValid(i, j, curr))
            continue;

        curr[i][j] = 'Q';
        nqueen(i + 1, ans, curr);
        curr[i][j] = '.';
    }
}

vector<vector<string>> solveNQueens(int n)
{

    vector<vector<string>> ans;
    string str = "";
    for (int i = 0; i < n; i++)
        str += '.';
    vector<string> curr(n, str);
    nqueen(0, ans, curr);

    return ans;
}

int main()
{

    return 0;
}