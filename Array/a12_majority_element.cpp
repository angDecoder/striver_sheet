#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int


// if majority element exists then 
// it can make pair with all other element 
// and still have extra left
int majorityElement(vector<int> &v)
{
    int n = v.size();
    int cnt = 0, elem = v[0];

    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
            elem = v[i];

        if (elem == v[i])
            cnt++;
        else
            cnt--;
    }

    return elem;
}

int main()
{

    return 0;
}