#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

#include <bits/stdc++.h>
/*
    This is signature of helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B);
    Function 'knows(A, B)' will returns "true" if the person having
    id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    while (st.size() >= 2)
    {
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();

        if (knows(first, second))
            st.push(second);
        else
            st.push(first);
    }

    int cand = st.top();
    int i = 0;
    while (i < n and (knows(i, cand) == 1 and knows(cand, i) == 0 or i == cand))
        i++;

    if (i == n)
        return cand;
    return -1;
}

int main()
{

    return 0;
}