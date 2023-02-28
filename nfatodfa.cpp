#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

void nfatodfa( vector<map<int,vector<int>>>&graph,vector<int>&input ){
    set<vector<int>> s;
    s.insert({0});
    
}

int main()
{
    int n,e,in; cin>>n>>e>>in;
    vector<int> input(in);
    for( int i=0; i<in;i++ ){
        cin>>input[i];
    }

    vector<map<int,vector<int>>> graph(n);
    for( int i=0; i<e; i++ ){
        int st,inp,res;
        cin>>st>>inp>>res;
        graph[st][inp].push_back(res);
    }

    nfatodfa(graph,input);
  
  return 0;
}