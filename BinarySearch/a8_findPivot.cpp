#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int findPivot(vector<int> &v)
{
    int n = v.size();
    int i = 0, j = n - 1;
    int cnt = 0;

    while (j-i>1)
    {
        int mid = (i + j) / 2;
        if (v[j] >= v[i])
            return i;
        if (v[mid] > v[i])
            i = mid;
        else if (v[j] > v[mid])
            j = mid;
    }

    if( v[i]<v[j] )
        return i;
    return j;
}

int main()
{
    vector<int> v = {0,1,2,3,4};
    cout<<findPivot(v);
    return 0;
}