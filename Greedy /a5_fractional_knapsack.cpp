#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

struct Item{
    int value;
    int weight;
};

bool cmp(Item &a, Item &b)
{
    double a1 = a.value * 1.00 / a.weight;
    double b1 = b.value * 1.00 / b.weight;

    return a1 >= b1;
}

// Function to get the maximum total value in the knapsack.
double fractionalKnapsack(double w, Item arr[], int n)
{
    sort(arr, arr + n, cmp);
    int i = 0;
    double profit = 0;
    while (i < n and w - arr[i].weight >= 0)
    {
        w -= arr[i].weight;
        profit += arr[i].value;
        i++;
    }

    if (w > 0 and i < n)
    {
        profit += arr[i].value * w / arr[i].weight;
    }

    return profit;
}

int main()
{

    return 0;
}