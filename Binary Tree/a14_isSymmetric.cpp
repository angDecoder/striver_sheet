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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL and q == NULL)
        return true;

    if (p == NULL or q == NULL)
        return false;

    if (p->val != q->val)
        return false;

    bool ans1 = isSameTree(p->left, q->right);
    bool ans2 = isSameTree(p->right, q->left);

    return (ans1 and ans2);
}

bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;

    return isSameTree(root->left, root->right);
}

int main()
{

    return 0;
}