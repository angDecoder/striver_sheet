#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int findMaxConsecutiveOnes(vector<int> &v)
{
    int n = v.size();
    int i = 0, j = 0;
    int res = 0;
    while (i < n)
    {
        while (j < n and v[j] == 1)
            j++;

        res = max(j - i, res);
        i = ++j;
    }

    return res;
}

int main()
{

    return 0;
}