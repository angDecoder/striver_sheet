#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int kmp( string &a, string &b ){
    string s = b + "#" + a;
    int i = 1,len = 0,ans = 0;
    vector<int> lps(s.size(),0);
    while( i<s.size() ){
        if( s[i]==s[len] ){
            len++;
            ans = max(ans,len);
            lps[i] = len;
            i++;
        }
        else{
            if( len>0 )
                len = lps[len-1];
            else
                i++;
        }
    }

    return ans;
}

void solve(){
    int n; cin>>n;
    vector<string> v(n);
    int res = 0;
    for( int i=0; i<n; i++ ){
        cin>>v[i];
        reverse(v[i].begin(),v[i].end());
        if( i>0 )
            res += v[0].size() - kmp(v[0],v[i]);
       
    }

    // cout<<res<<endl;

}

int main()
{
    solve();
  
  return 0;
}