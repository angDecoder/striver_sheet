#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

double pow(double x, int n)
{
    if (n == 0)
        return 1.00;
    double res = pow(x, n / 2);
    if (n % 2 == 0)
        return res * res;
    return res * res * x;
}

double myPow(double x, int n)
{
    double ans = pow(x, n);
    if (n < 0)
        return 1 / ans;
    return ans;
}

int main()
{

    return 0;
}