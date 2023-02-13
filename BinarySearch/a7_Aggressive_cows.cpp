#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int
// https://leetcode.com/problems/magnetic-force-between-two-balls/
int getCows( vector<int>&v, int d ){
    int n = v.size();
    int i = 0;
    int ans = 1;
    for( int j=1; j<n; j++ ){
        if( v[j]-v[i]>=d )
            ans++,i = j;
    }

    return ans;
}

void solve(){
    int n,c; cin>>n>>c;
    vector<int>v(n);
    for( int i=0; i<n; i++ )
        cin>>v[i];
    
    sort(v.begin(),v.end());

    int start = v[n-1]-v[0], end = v[n-1]-v[0];
    for( int i=1; i<n; i++ )
        start = min(start,v[i]-v[i-1]);
    
    while( end-start>1 ){
        int mid = start+(end-start)/2;
        int res = getCows(v,mid);

        if( res==c )
            start = mid;
        else if( res>c )
            start = mid;
        else    
            end = mid-1;
    }

    cout<<start<<" "<<end<<endl;
    // if( getCows(v,end)>=c )
    //     cout<<end<<endl;
    // else if( getCows(v,start)>=c )
    //     cout<<start<<endl;
    // else 
    //     cout<<-1<<endl;

    // for( int i=start; i<=end; i++ ){
    //     cout<<i<<" "<<getCows(v,i)<<endl;
    // }

    // 1 5
    // 2 3
    // 3 3
    // 4 2
    // 5 2
    // 6 2
    // 7 2
    // 8 2
}

int main()
{
    ll t; cin>>t;
    while( t-- ){
     solve();
    }
    return 0;
}