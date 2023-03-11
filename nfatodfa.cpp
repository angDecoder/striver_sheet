#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int hammingDistance( int a, int b ){
    int ans = 0;
    int x = a^b;
    while( x>0 ){
        if( x%2 )
            ans++;
            
        x = x/2;
    }

    return ans;
}

int main()
{
    int a,b; cin>>a>>b;
    cout<<hammingDistance(a,b);
  
  return 0;
}