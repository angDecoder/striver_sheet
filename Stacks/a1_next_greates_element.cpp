#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

vector<int> nextGreaterElements(vector<int> &v)
{
    int n = v.size();
    vector<int> ans(n);
    stack<int> st;
    for (int j = 0; j < 2; j++)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and st.top() <= v[i])
                st.pop();

            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(v[i]);
        }
    }

    return ans;
}

int main()
{

    return 0;
}