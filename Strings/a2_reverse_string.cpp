#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int


    string reverseWords(string s)
    {
        int i = 0, j = 0, n = s.size();
        string ans = "";
        while (i < n)
        {
            while (j < n and s[j] == ' ')
                j++;
            i = j;
            if (i == n)
                break;

            while (j < n and s[j] != ' ')
                j++;

            ans = s.substr(i, j - i) + ' ' + ans;
            i = j;
        }

        ans.pop_back();

        return ans;
    }


int main()
{

    return 0;
}