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
    TreeNode *build(vector<int> &pre, int start, int end)
    {
        if (start > end)
            return NULL;

        TreeNode *curr = new TreeNode(pre[start]);
        int i = start;
        while (i <= end and pre[start] >= pre[i])
            i++;
        curr->left = build(pre, start + 1, i - 1);
        curr->right = build(pre, i, end);

        return curr;
    }

    TreeNode *bstFromPreorder(vector<int> &pre)
    {
        int n = pre.size();

        return build(pre, 0, n - 1);
    }
};

int main()
{

    return 0;
}