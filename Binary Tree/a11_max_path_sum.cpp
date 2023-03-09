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

int getSum(TreeNode *root, int &ans)
{
    if (root == NULL)
        return 0;

    int leftSum = getSum(root->left, ans);
    int rightSum = getSum(root->right, ans);

    ans = max(ans, max({leftSum + rightSum, leftSum, rightSum, 0}) + root->val);

    return root->val + max({leftSum, rightSum, 0});
}

int maxPathSum(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int ans = root->val;
    getSum(root, ans);

    return ans;
}

int main()
{

    return 0;
}