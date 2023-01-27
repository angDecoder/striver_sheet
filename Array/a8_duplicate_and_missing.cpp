#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

/*
  // binary search approach

int cntNum( vector<int> &v, int num ){
    int n = v.size();
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        if( v[i]<=num )
            ans++;
    }

    return ans;
}

int findDuplicate(vector<int> &v)
{
    int n = v.size();
    int start = 1, end = n;
    while( end>start+1 ){
        int mid = start + (end-start)/2;
        if( cntNum(v,mid)>mid )
            end = mid;
        else
            start = mid+1;
    }

    if( cntNum(v,start)>start )
        return start;
    return end;
}
*/


    // floyd's cycle detection
int findDuplicate(vector<int> &v)
{
    int n = v.size();
    int fast = 0,slow = 0;
    do{
        fast = v[v[fast]];
        slow = v[slow];
    }while( fast!=slow );
    fast = 0;
    while( fast!=slow ){
        fast = v[fast];
        slow = v[slow];
    }

    return fast;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << findDuplicate(v);

    return 0;
}