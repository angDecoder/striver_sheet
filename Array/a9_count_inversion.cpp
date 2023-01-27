#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

ll merge(ll *arr, int start, int mid, int end, vector<ll> &v)
{
    ll inv = 0;
    int i = start, j = mid + 1;
    int k = start;
    while (i <= mid and j <= end)
    {
        if (arr[i] <= arr[j])
        {
            v[k++] = arr[i++];
        }
        else
        {
            v[k++] = arr[j++];
            inv += (mid - i + 1);
        }
    }

    while (i <= mid)
    {
        v[k++] = arr[i++];
    }
    while (j <= end)
    {
        v[k++] = arr[j++];
    }

    for (int i = start; i <= end; i++)
        arr[i] = v[i];

    return inv;
}

ll mergeSort(ll *arr, int start, int end, vector<ll> &v)
{

    if (start >= end)
        return 0;

    int mid = (start + end) / 2;
    ll a = mergeSort(arr, start, mid, v);
    ll b = mergeSort(arr, mid + 1, end, v);

    ll c = merge(arr, start, mid, end, v);

    return a + b + c;
}

ll getInversions(ll *arr, int n)
{

    vector<ll> vr(n);
    return mergeSort(arr, 0, n - 1, vr);
}

int main()
{

    return 0;
}