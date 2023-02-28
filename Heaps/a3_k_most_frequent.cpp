#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

vector<int> topKFrequent(vector<int> &v, int k)
{
    unordered_map<int, int> m;
    int n = v.size();
    for (int i = 0; i < n; i++)
        m[v[i]]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (auto elem : m)
    {
        pq.push({elem.second, elem.first});
        if (pq.size() > k)
            pq.pop();
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}

int main()
{

    return 0;
}