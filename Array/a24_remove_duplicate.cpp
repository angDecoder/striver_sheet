#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int removeDuplicates(vector<int> &v)
{
    int n = v.size();
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (v[j] != v[j - 1])
            v[++i] = v[j];
    }

    return i + 1;
}

int main()
{

    return 0;
}