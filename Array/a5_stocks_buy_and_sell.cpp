#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

vector<vector<int>> dp(1000,vector<int>(100,INT_MIN));


// part 4 
int maxProfit(int k, vector<int> &v, int buy = -1, int i = 0)
{
    int n = v.size();
    if( i>=n or k==0 )
        return 0;
    
    if( buy==-1 ){
        
        if( dp[i][k] !=INT_MIN )
            return dp[i][k] ;
        
        int a = maxProfit(k,v,v[i],i+1) - v[i];
        int b = maxProfit(k,v,-1,i+1);

        return dp[i][k]  = max(a,b);
    }

    int a=0,b=0;
    if( v[i]>buy )
        a = maxProfit(k-1,v,-1,i+1) + v[i];
    
    b = maxProfit(k,v,buy,i+1);

    return max(a,b);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << maxProfit(k, v)<<endl;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << dp[i][j]<< " ";
        }
        cout << endl;
    }


    return 0;
}