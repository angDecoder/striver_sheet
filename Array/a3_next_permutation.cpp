#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void nextPermutation(vector<int> &v)
{
    // 1 3 ( 5 4 2 ) --> can't make larger value with elems in bracket
    // so we have to enlarge the bracket

    int n = v.size();
    int i = n - 2;
    while (i >= 0 and v[i] >= v[i + 1])
        i--;

    sort(v.begin() + i + 1, v.end());
    if (i >= 0)
    {
        int upp = upper_bound(v.begin() + i + 1, v.end(), v[i]) - v.begin();
        if (upp < n)
            swap(v[i], v[upp]);
    }

    // return v;
}

int main()
{

    return 0;
}