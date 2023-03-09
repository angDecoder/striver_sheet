#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

class TreeNode
{
public:
    TreeNode *left, *right;
    int val;

    TreeNode( int v,TreeNode*l=NULL,TreeNode*r=NULL ){
        val = v;
        left = l,right = r;
    }
};

void inorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    inorder(root, ans);

    return ans;
}

int main()
{

    return 0;
}