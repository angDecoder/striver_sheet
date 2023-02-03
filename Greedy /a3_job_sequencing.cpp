#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

bool cmp( Job &a,Job &b ){
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr,arr+n,cmp);
    vector<int> pro(n+7,0);
    int job = 0, res = 0;
    for( int i=0; i<n; i++ ){
        int j = arr[i].dead;
        while( j>=1 ){
            if( pro[j]==0 ){
                pro[j] = arr[i].profit;
                job++,res += pro[j];
                break;
            }
            j--;
        }
    }
    
    return {job,res};
}

int main()
{

    return 0;
}