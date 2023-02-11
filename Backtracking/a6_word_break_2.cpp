#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

bool isValid( string&s,vector<string>&dict ){
    for( auto &str : dict ){
        if( str==s )
            return true;
    }

    return false;
}

void solve(int i,string &s,vector<string>&dict,vector<string>&ans,string curr){
    int n = s.size();
    if( i==n ){
        ans.push_back(curr.substr(1));
        return;
    }

    for(int j=i;j<n;j++ ){
        string str = s.substr(i,j-i+1);

        if( !isValid(str,dict) )
            continue;

        solve(j+1,s,dict,ans,curr+" "+str);
    }
}

vector<string> wordBreak(string &s, vector<string> &dict)
{
    vector<string> ans;
    solve(0,s,dict,ans,"");
    return ans;
}

int main()
{
  
  return 0;
}