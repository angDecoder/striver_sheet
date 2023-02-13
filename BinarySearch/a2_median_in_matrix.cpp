#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int solve(vector<vector<int>> &v, int mid)
{
    int ans = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        ans += upper_bound(v[i].begin(), v[i].end(), mid) - v[i].begin();
    }

    return ans;
}

int findMedian(vector<vector<int>> &v)
{
    int n = v.size(), m = v[0].size();
    int start = 0, end = 1e9+7;
    int tar = (m*n)/2;
    
    while( end-start>1 ){
    int mid = start + (end-start)/2;

    if( solve(v,mid)==tar )
      start = mid+1;
    else if( solve(v,mid)<tar )
      start = mid+1;
    else 
      end = mid;
  }

  if( solve(v,start)>tar )
    return start;
  
  return end;
}

int main()
{
    cout<<"hello world";

    return 0;
}