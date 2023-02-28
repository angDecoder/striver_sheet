#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int largestRectangleArea(vector<int> &h)
{
    int n = h.size();
    vector<int> v(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and h[st.top()] >= h[i])
            st.pop();

        v[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while (!st.empty())
        st.pop();

    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() and h[st.top()] >= h[i])
            st.pop();

        int res = st.empty() ? n : st.top();
        st.push(i);
        int curr = ((i - v[i]) + (res - i - 1)) * h[i];
        ans = max(ans, curr);
    }

    return ans;
}

// one pass;
/*
    if index j is getting popped by index i then 
    next smaller element for index j is i

    and previous smaller element will be element 
    just under the current element in stack
*/
int largestRectangleArea1(vector<int> &h)
{
    h.push_back(0);
    int n = h.size();
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and h[st.top()] >= h[i])
        {
            int curr = h[st.top()];
            st.pop();
            int prev = st.empty() ? -1 : st.top();
            int l = i - prev - 1;
            ans = max(ans, l * curr);
        }
        st.push(i);
    }

    return ans;
}

int main()
{

    return 0;
}