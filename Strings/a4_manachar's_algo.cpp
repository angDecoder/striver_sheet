#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int


/*
    1. pre-process the string 
    2. find the mirror image to give a head start
    3. update the right boundary
*/

vector<int> manacharAlgo( string s ){
    string str = "@#";
    for(int i=0; i<s.size(); i++)
    {
        str.push_back(s[i]);
        str.push_back('#');
    }
    str.push_back('$');

    int mirr = 0, right = 0;
    vector<int> lps(str.size(),0);
    for(int i=1; i<str.size(); i++)
    {
        int mimg = mirr-(i-mirr);

        if( i<=right )
            lps[i] = min(right-i,lps[mimg]);

        while( str[i+lps[i]+1]==str[i-lps[i]-1] )
            lps[i]++;

        if( i+lps[i]>right ){
            mirr = i;
            right = i+lps[i];
        }
    }

    return lps;
}

int main()
{
    string s; cin>>s;
    vector<int> v = manacharAlgo(s);
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
  
  return 0;
}