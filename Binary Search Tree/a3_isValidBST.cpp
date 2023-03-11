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
    bool isValidBST(TreeNode *root)
    {
        if (root == NULL)
            return true;

        bool ans = true;
        if (root->left)
        {
            TreeNode *temp = root->left;
            while (temp->right)
                temp = temp->right;

            ans = root->val > temp->val && isValidBST(root->left);
        }

        if (!ans)
            return false;

        if (root->right)
        {
            TreeNode *temp = root->right;
            while (temp->left)
                temp = temp->left;

            ans = root->val < temp->val && isValidBST(root->right);
        }

        return ans;
    }
};

int main()
{

    return 0;
}