#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int lowerBound(vector<int>&v, int tar ){
  int n = v.size();
  int start = 0,end = n-1;

  while( end-start>1 ){
    int mid = start + (end-start)/2;
    if( v[mid]==tar )
      end = mid;
    else if( v[mid]<tar )
      start = mid+1;
    else 
      end = mid;
  }

  if( v[start]==tar )
    return start;
  return end;
}

int upperBound( vector<int>&v,int tar ){
  int n = v.size();
  int start = 0, end = n-1;

  while( end-start>1 ){
    int mid = start + (end-start)/2;

    if( v[mid]==tar )
      start = mid+1;
    else if( v[mid]<tar )
      start = mid+1;
    else 
      end = mid;
  }

  if( v[start]>tar )
    return start;
  
  return end;

}

int lastPart( vector<int>&v, int tar ){
  int n = v.size();
  int start = 0, end = n-1;
  while( end-start>1 ){
    int mid = start + (end-start)/2;

    if( v[mid]==tar )
      start = mid;
    else if( v[mid]<tar )
      start = mid+1;
    else 
      end = mid;
  }

  if( v[start]>=tar )
    return start;

  return end;
}

int main()
{
  int n,t; cin>>n>>t;
  vector<int> v(n);
  for( int i=0; i<n; i++ ){
    cin>>v[i];
  }
  sort(v.begin(),v.end());
  cout<<lowerBound(v,t)<<endl;
  cout<<upperBound(v,t)<<endl;
  cout<<lastPart(v,t)<<endl;
  
  return 0;
}