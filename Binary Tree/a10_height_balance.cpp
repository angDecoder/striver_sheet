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

int solve(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int d1 = solve(root->left);
    int d2 = solve(root->right);

    if (d1 == -1 or d2 == -1)
        return -1;

    if (abs(d1 - d2) <= 1)
        return max(d1, d2) + 1;

    return -1;
}

bool isBalanced(TreeNode *root)
{
    return solve(root) != -1;
}

int main()
{
    deque<int> q;
    
    return 0;
}