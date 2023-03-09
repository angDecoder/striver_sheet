#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

string longestPalindrome1(string s)
{
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    string ans = "";

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
                dp[i][j] = true;
            else if (s[i] == s[j])
            {
                if (j == i + 1 or dp[i + 1][j - 1])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
            else
                dp[i][j] = false;

            if (dp[i][j] and j - i + 1 > ans.size())
                ans = s.substr(i, j - i + 1);
        }
    }

    return ans;
}

vector<int> manacharAlgo(string &str)
{
    string s = "@#";
    for (int i = 0; i < str.size(); i++)
    {
        s.push_back(str[i]);
        s.push_back('#');
    }
    s.push_back('$');

    vector<int> lps(s.size(), 0);

    int mirr = 0, right = 0;
    for (int i = 1; i < s.size(); i++)
    {
        int mimg = mirr - (i - mirr);
        if (i <= right)
            lps[i] = min(right - i + 1, lps[mimg]);

        while (s[i + lps[i] + 1] == s[i - lps[i] - 1])
            lps[i]++;

        if (i + lps[i] > right)
        {
            mirr = i;
            right = i + lps[i];
        }
    }

    return lps;
}

int findRange(vector<int> &lps, int i)
{
    return ((i - lps[i] + 1)-2)/2;
}

string longestPalindrome(string s)
{
    vector<int> lps = manacharAlgo(s);
    int maxElem = 0, l = 0;
    for (int i = 0; i < lps.size(); i++)
    {
        if (lps[i] > maxElem)
        {
            maxElem = lps[i];
            l = findRange(lps, i);
            // cout<<i<<" "<<l<<" "<<maxElem<<endl;
        }
    }

    return s.substr(l, maxElem);
}

int main()
{
    string s; cin>>s;
    cout<<longestPalindrome(s);

    return 0;
}