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

TreeNode *build(int ini, int inj, vector<int> &ino, int pi, int pj, vector<int> &post)
{
    if (ini > inj or pi > pj)
        return NULL;

    TreeNode *curr = new TreeNode(post[pj]);

    int root = pos[post[pj]];
    int left = root - ini;
    int right = (inj - ini + 1) - left - 1;

    if (left)
        curr->left = build(ini, root - 1, ino, pi, pi + left - 1, post);
    if (right)
        curr->right = build(root + 1, inj, ino, pi + left, pj - 1, post);

    return curr;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int n = inorder.size();
    for (int i = 0; i < n; i++)
    {
        pos[inorder[i]] = i;
    }

    return build(0, n - 1, inorder, 0, n - 1, postorder);
}

int main()
{

    return 0;
}