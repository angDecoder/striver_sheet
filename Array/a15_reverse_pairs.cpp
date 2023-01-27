#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int



    
int mergeSort(vector<int> &v, vector<int> &temp, int start, int end)
{
    if( start>=end )
        return 0;
    int mid = (start+end)/2;
    int a = mergeSort(v,temp,start,mid);
    int b = mergeSort(v,temp,mid+1,end);
    int c = merge(v,temp,start,mid,end);

    return a+b+c;
}

int merge(vector<int> &v, vector<int> &temp, int start, int mid, int end)
{
    int inv = 0;
    int i = start, j = mid+1, k = start;
    while( i<=mid ){
        while( j<=end and (long)v[i]>(long)v[j]*2 )
            j++;

        inv += j-mid-1;
        i++;
    }
    i = start, j = mid+1, k = start;
    while( i<=mid and j<=end ){
        if( v[i]<=v[j] )
            temp[k++] = v[i++];
        else 
            temp[k++] = v[j++];
    }

    while( i<=mid )
        temp[k++] = v[i++];
    while( j<=end )
        temp[k++] = v[j++];

    for( int i=start; i<=end; i++)
        v[i] = temp[i];

    return inv;

}

int reversePairs(vector<int> &v)
{
    int n = v.size();
    vector<int> temp(n);

    return mergeSort(v,temp,0,n-1);
}




int main()
{
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }

    cout<<reversePairs(v);
  
  return 0;
}