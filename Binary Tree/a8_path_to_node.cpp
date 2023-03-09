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

bool getPath(TreeNode *root, int tar, vector<int> &ans)
{
    if (root == NULL)
        return false;
    if (root->val == tar)
    {
        ans.push_back(tar);
        return true;
    }

    ans.push_back(root->val);
    if (getPath(root->left, tar, ans))
        return true;
    if (getPath(root->right, tar, ans))
        return true;

    ans.pop_back();
    return false;
}

vector<int> solve(TreeNode *root, int tar)
{
    vector<int> ans;
    getPath(root, tar, ans);

    return ans;
}

int main()
{
    TreeNode *node = new TreeNode(0);

    return 0;
}