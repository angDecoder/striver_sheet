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

void preorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    // preorder(root,ans);
    TreeNode *curr = root;
    while (curr != NULL)
    {
        // ans.push_back(curr->val)
        if (curr->left)
        {
            TreeNode *temp = curr->left;
            while (temp->right and temp->right != curr)
                temp = temp->right;

            if (temp->right)
            {
                temp->right = NULL;
                curr = curr->right;
            }
            else
            {
                ans.push_back(curr->val);
                temp->right = curr;
                curr = curr->left;
            }
        }
        else
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }

    return ans;
}

int main()
{

    return 0;
}