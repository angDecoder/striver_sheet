#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int


int trap(vector<int> &h)
{
    int n = h.size();
    int left = 0, right = n - 1;
    int maxLeft = h[0], maxRight = h[n - 1];
    int res = 0;
    while (left <= right)
    {
        // water stored at index i 
        // will depend on min ( maxleft,maxright ) 
        // index having smaller smaller value will be updated
        if (h[left] <= h[right])
        {
            maxLeft = max(maxLeft, h[left]);
            res += maxLeft - h[left];
            left++;
        }
        else
        {
            maxRight = max(maxRight, h[right]);
            res += maxRight - h[right];
            right--;
        }
    }

    return res;
}

int main()
{

    return 0;
}