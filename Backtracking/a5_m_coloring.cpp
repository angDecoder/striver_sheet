#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> color(n, 0);
    return solve(0, m, n, graph, color);
}

bool solve(int node, int m, int n, bool graph[101][101], vector<int> &color)
{
    if (node == n)
        return true;

    for (int i = 1; i <= m; i++)
    {
        if (!isValid(node, n, i, graph, color))
            continue;

        color[node] = i;
        if (solve(node + 1, m, n, graph, color))
            return true;
        color[node] = 0;
    }

    return false;
}

bool isValid(int node, int n, int c, bool graph[101][101], vector<int> &color)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] and color[i] == c)
            return false;
    }

    return true;
}

int main()
{

    return 0;
}