#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

class TreeNode
{
public:
    TreeNode *left, *right;
    int val;

    TreeNode(int v, TreeNode *l = NULL, TreeNode *r = NULL)
    {
        val = v;
        left = l, right = r;
    }
};
class Solution
{
public:
    TreeNode *build(vector<int> &v, int start, int end)
    {
        if (start > end)
            return NULL;

        int mid = (start + end) / 2;
        TreeNode *curr = new TreeNode(v[mid]);

        curr->left = build(v, start, mid - 1);
        curr->right = build(v, mid + 1, end);

        return curr;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int n = nums.size();
        return build(nums, 0, n - 1);
    }
};

int main()
{

    return 0;
}