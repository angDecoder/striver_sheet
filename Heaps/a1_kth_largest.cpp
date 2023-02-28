#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int findKthLargest(vector<int> &v, int k)
{
    priority_queue<int, vector<int>, greater<int>> q;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        q.push(v[i]);
        if (q.size() > k)
        {
            q.pop();
        }
    }

    return q.top();
}

int main()
{

    return 0;
}