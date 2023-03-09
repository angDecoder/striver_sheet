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

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    TreeNode *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            TreeNode *temp = curr->left;
            while (temp->right and temp->right != curr)
                temp = temp->right;

            if (temp->right == curr)
            {
                temp->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                temp->right = curr;
                curr = curr->left;
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}