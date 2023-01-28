#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    int j = 0, i = 0;
    int ans = 0, curr = 0;
    vector<int> v(256, 0);
    while( i<n )
    {
        if (j < n and v[s[j]] == 0)
        {
            curr++, v[s[j]]++;
            j++;
        }
        else
        {
            v[s[i]]--;
            if (v[s[i]] == 0)
                curr--;
            i++;
        }

        ans = max(ans, curr);
    }

    return ans;
}

int main()
{
    string s = "aab";
    cout<<lengthOfLongestSubstring(s);

    return 0;
}