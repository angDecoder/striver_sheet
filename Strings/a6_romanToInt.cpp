#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int romanToInt(string s)
{
    unordered_map<char, int> m;
    s.push_back('K');
    m['K'] = 0;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int ans = 0;
    for (int i = s.size() - 2; i >= 0; i--)
    {
        if (m[s[i]] >= m[s[i + 1]])
            ans += m[s[i]];
        else
            ans -= m[s[i]];
    }

    return ans;
}

int main()
{

    return 0;
}