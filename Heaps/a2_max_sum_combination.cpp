#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int
#define ppi pair<int, pair<int, int>>
#define pr pair<int, int>

vector<int> solve(vector<int> &A, vector<int> &B, int C) {
   
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
   
    set<vector<int>> s;
    priority_queue<vector<int>> pq;
    pq.push({A[0]+B[0],0,0});
   
    int cnt=0;
    vector<int> ans;
    while(cnt<C){
        auto top=pq.top();
        pq.pop();
        int i=top[1];
        int j=top[2];
        ans.push_back(top[0]);
       
        auto f1=s.find({i+1,j});
        auto f2=s.find({i,j+1});
       
        if(f1==s.end() and i+1<A.size()){
            pq.push({A[i+1]+B[j],i+1,j});
            s.insert({i+1,j});
        }
       
        if(f2==s.end() and j+1<B.size()){
            pq.push({A[i]+B[j+1],i,j+1});
            s.insert({i,j+1});
        }
        cnt++;
    }
   
    return ans;
}
int main()
{

    return 0;
}