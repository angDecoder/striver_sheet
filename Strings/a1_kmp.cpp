#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

vector<int> kmp( string str, string patt ){
  string s = patt + "$" + str;
  int n = s.size();
  vector<int> lps(n,0);
  int len = lps[0], i = 1;
  while( i<n ){
    if( s[i]==s[len] ){
      len++;
      lps[i] = len;
      i++;
    }
    else{
      if( len>0 )
        len = lps[len-1];
      else
        len = lps[i] = 0, i++;
    }
  }

  return lps;
}

int main()
{
  string s,patt; cin>>s>>patt;
  vector<int> lps = kmp(s,patt);

  int ans = 0;
  for(int i=0; i<lps.size(); i++)
  {
    if( lps[i]==patt.size() )
      ans++;
  }
  cout<<ans<<endl;
  
  return 0;
}