#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int coinChange(vector<int> &coins, int amt)
{
    // sort(coins.begin(),coins.end());
    vector<int> v(amt + 7, amt + 7);
    v[0] = 0;
    for (int i = 1; i <= amt; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (i >= coins[j])
                v[i] = min(v[i], v[i - coins[j]] + 1);
        }
    }

    return v[amt] > amt ? -1 : v[amt];
}

int main()
{

    return 0;
}