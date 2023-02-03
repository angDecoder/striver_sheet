#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        v[i] = {end[i], start[i]};

    sort(v.begin(), v.end());

    int ans = 1;
    int time = v[0].first;
    for (int i = 1; i < n; i++)
    {
        if (v[i].second > time)
            ans++, time = v[i].first;
    }

    return ans;
}

int main()
{

    return 0;
}