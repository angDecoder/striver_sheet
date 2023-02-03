#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr,arr+n);
    sort(dep,dep+n);

    int curr = 0, ans = 0;
    int j = 0;
    for(int i=0; i<n; i++)
    {
        while( j<n and dep[j]<arr[i] )
            j++,curr--;
            
        ans = max(ans,++curr);
    }

    return ans;

}

int main()
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dept[] = {910, 1200, 1120, 1130, 1900, 2000};

    cout<<findPlatform(arr,dept,6)<<endl;

    return 0;
}