#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int findDuplicate(vector<int> &v)
{
    int n = v.size();
    int x = 0;
    for (int i = 0; i < n; i++)
        x ^= (i + 1) ^ v[i];

    x = x & -x;

    int one = 0, zero = 0;
    for (int i = 0; i < n; i++)
    {
        if (x & (i + 1))
            one ^= (i + 1);
        else
            zero ^= (i + 1);

        if (x & v[i])
            one ^= v[i];
        else
            zero ^= v[i];
    }
    cout<<one<<" "<<zero<<endl;
    for(int i=0; i<n; i++)
    {
        if( v[i]==one )
            return one;
    }

    return zero;
}

int main()
{
    int n; cin>>n; 
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }

    cout<<findDuplicate(v);

    return 0;
}