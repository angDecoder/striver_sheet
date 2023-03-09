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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    int currh = -1;
    int i = -1;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto curr = q.front();
        auto *node = curr.first;
        int h = curr.second;
        q.pop();
        if (currh == h)
            ans[i].push_back(node->val);
        else
        {
            currh = h;
            i++;
            ans.push_back({node->val});
        }

        if (node->left)
            q.push({node->left, h + 1});
        if (node->right)
            q.push({node->right, h + 1});
    }

    return ans;
}

int main()
{

    return 0;
}