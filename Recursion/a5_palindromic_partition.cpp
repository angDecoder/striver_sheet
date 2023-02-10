#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> curr;

    getPart(s, 0, 0, ans, curr);

    return ans;
}

void getPart(string &s, int i, int j, vector<vector<string>> &ans, vector<string> &curr)
{
    int n = s.size();

    if (i == j and i == n)
    {
        ans.push_back(curr);
        return;
    }
    if (i >= n or j >= n)
        return;

    if (isPalindrome(s, i, j))
    {
        curr.push_back(s.substr(i, j - i + 1));
        getPart(s, j + 1, j + 1, ans, curr);
        curr.pop_back();
    }

    getPart(s, i, j + 1, ans, curr);
}

bool isPalindrome(string &s, int i, int j)
{
    while (j >= i)
    {
        if (s[i] != s[j])
            return false;
        i++, j--;
    }

    return true;
}

int main()
{

    return 0;
}