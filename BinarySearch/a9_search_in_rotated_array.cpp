#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

int findPivot(vector<int> &v)
{
    int n = v.size();
    int i = 0, j = n - 1;
    int cnt = 0;

    while (j - i > 1)
    {
        int mid = (i + j) / 2;
        if (v[j] >= v[i])
            return i;
        if (v[mid] > v[i])
            i = mid;
        else if (v[j] > v[mid])
            j = mid;
    }

    if (v[i] < v[j])
        return i;
    return j;
}

int binSearch(vector<int> &v, int i, int j, int tar)
{

    while (j >= i)
    {
        int mid = (i + j) / 2;
        if (v[mid] == tar)
            return mid;
        else if (tar > v[mid])
            i = mid + 1;
        else
            j = mid - 1;
    }

    return -1;
}

int search(vector<int> &v, int tar)
{
    int n = v.size();
    int p = findPivot(v);
    int a = binSearch(v, p, n - 1, tar);
    if (a == -1)
        a = binSearch(v, 0, p - 1, tar);

    return a;
}

int main()
{

    return 0;
}