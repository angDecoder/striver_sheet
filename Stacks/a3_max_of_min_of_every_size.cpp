#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

vector<int> maxMinWindow(vector<int> v, int n)
{
    v.push_back(INT_MIN);
    vector<int> ans(n, INT_MIN);
    stack<int> st;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() and v[st.top()] >= v[i])
        {
            int curr = v[st.top()];
            st.pop();
            int prev = st.empty() ? -1 : st.top();
            int ws = i - prev - 1;
            if (ws <= n)
                ans[ws - 1] = max(ans[ws - 1], curr);

            // cout<<ws<<" "<<ans[ws-1]<<" "<<endl;
        }

        st.push(i);
    }

    int maxElem = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = max(ans[i], maxElem);
        maxElem = ans[i];
    }

    return ans;
}

int main()
{
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }

    vector<int> ans = maxMinWindow(v,n);
    for(int i=0; i<n; i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}