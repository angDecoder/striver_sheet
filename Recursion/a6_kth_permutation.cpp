#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

string kthPermutation(int n, int k, vector<bool> &v, vector<int> &fact)
{
    if (n == 0)
        return "";

    int num = k % fact[n - 1] == 0 ? k / fact[n - 1] : (k / fact[n - 1]) + 1;
    int cnt = 0, i = 1;
    while (cnt < num)
    {
        if (v[i])
            cnt++;
        if (cnt == num)
            break;
        i++;
    }
    v[i] = false;
    k = k - (num - 1) * fact[n - 1];
    return to_string(i) + kthPermutation(n - 1, k, v, fact);
}

string getPermutation(int n, int k)
{
    vector<bool> v(n + 1, true);
    vector<int> fact(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i;
    }
    return kthPermutation(n, k, v, fact);
}

int main()
{

    return 0;
}