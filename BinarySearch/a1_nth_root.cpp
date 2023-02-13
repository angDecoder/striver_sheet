#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

double pow(double num, int n)
{
    if (n == 0)
        return 1.00;
    double ans = pow(num, n / 2);
    if (n % 2 == 0)
        return ans * ans;
    return ans * ans * num;
}

double findNthRootOfM(int n, int m)
{
    double start = 0, end = m;
    double eps = 1e-10;
    double mid;
    // while( end-start>eps )
    for (int i = 0; i < 100; i++)
    {
        mid = start + (end - start) / 2;
        double res = pow(mid, n);

        if (res <= (double)m)
            start = mid;
        else
            end = mid;
    }

    return mid;
}

int main()
{

    return 0;
}