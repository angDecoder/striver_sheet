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

TreeNode *build(TreeNode *root)
{
    if (root == NULL)
        return NULL;

    auto *temp = root;
    auto *left = build(root->left);
    auto *right = build(root->right);

    temp->right = left;
    temp->left = NULL;
    while (temp->right)
        temp = temp->right;

    temp->right = right;

    return root;
}

void flatten(TreeNode *root)
{
    build(root);
}

int main()
{

    return 0;
}