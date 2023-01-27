#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

bool searchv(vector<vector<int>> &v, int t)
{
    int n = v.size(), m = v[0].size();
    int start = 0, end = (m * n) - 1;
    while (end >= start)
    {
        int mid = (start + end) / 2;
        // cout << start << " " << end << " " << mid << endl;
        int i = mid / m, j = mid % m;
        if (v[i][j] == t)
            return true;
        else if (v[i][j] > t)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return false;

}


int main()
{
    vector<vector<int>> v = {{1, 1}};
    cout << searchv(v, 2);

    return 0;
}