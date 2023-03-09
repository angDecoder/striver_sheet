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

unordered_map<int, int> pos;
TreeNode *build(int pri, int prj, vector<int> &pre, int ini, int inj, vector<int> &ino)
{
    if (pri > prj or ini > inj)
        return NULL;

    TreeNode *curr = new TreeNode(pre[pri]);

    int root = pos[pre[pri]];
    int left = root - ini;
    int right = (inj - ini + 1) - left - 1;

    if (left)
        curr->left = build(pri + 1, pri + left, pre, ini, root - 1, ino);
    if (right)
        curr->right = build(pri + left + 1, prj, pre, root + 1, inj, ino);

    return curr;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int n = preorder.size();
    for (int i = 0; i < n; i++)
    {
        pos[inorder[i]] = i;
    }

    return build(0, n - 1, preorder, 0, n - 1, inorder);
}

int main()
{

    return 0;
}