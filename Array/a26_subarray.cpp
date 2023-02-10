#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

vector<int> t;
int s = 2;
void merge( vector<int>&a,vector<int>&b ){
    int i = 0, j = 0;
    while( i<s and j<b.size() ){
        if(  )
    }
}

int findMax( vector<int>&v ){
    int n = v.size();
    t.resize(n+7);
    map<int,vector<int>> m;
    vector<int> temp(n+2,INT_MAX);
    temp[0] = -1;
    temp[1] = n+1;
    for( int i=0; i<n; i++ )
        m[v[i]].push_back(i);

    int ans = v[0];
    for( auto &elem : m ){
        vector<int> &a = elem.second;
        int maxLen = 1;
        for( int i=0; i<a.size(); i++ ){
            int idx = upper_bound(temp.begin(),temp.end(),a[i])-temp.begin();
            maxLen = max(maxLen,temp[idx]-temp[idx-1]-1);
        }
        ans = max(ans,maxLen*elem.first);
        merge(temp,a);
        s+=a.size();
    }

    return ans;
    
}

int main()
{
  
  return 0;
}