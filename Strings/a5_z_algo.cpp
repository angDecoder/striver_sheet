#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

vector<int> zAlgo(string str, string patt)
{
    string s = patt + "$" + str;
    vector<int> z(s.size(), 0);
    int left = 0, right = 0;
    for(int i=1; i<s.size(); i++)
    {
        if( i<=right )
            z[i] = min(right-i+1,z[i-left]);

        while( s[z[i]]==s[i+z[i]] )
            z[i]++;

        if( i+z[i]-1>right ){
            left = i;
            right = i+z[i]-1;
        }
    }

    return z;
}

int main()
{
    string s, patt;
    cin >> s >> patt;
    vector<int> lps = zAlgo(s, patt);

    int ans = 0;
    for (int i = 0; i < lps.size(); i++)
    {
        // cout<<lps[i]<<" ";
        if (lps[i] == patt.size())
            ans++;
    }
    cout<<endl;
    cout << ans << endl;

    return 0;
}