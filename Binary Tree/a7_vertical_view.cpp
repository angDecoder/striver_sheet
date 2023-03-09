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

void get(TreeNode *root, map<pair<int, int>, vector<int>> &m)
{
    if (root == NULL)
        return;
    queue<pair<TreeNode *, vector<int>>> q;
    q.push({root, {0, 0}}); // node , { h, d }

    while (!q.empty())
    {
        auto &curr = q.front();
        auto *node = curr.first;
        int h = curr.second[0];
        int d = curr.second[1];
        q.pop();

        m[{d, h}].push_back(node->val);
        if (node->left)
            q.push({node->left, {h + 1, d - 1}});
        if (node->right)
            q.push({node->right, {h + 1, d + 1}});
    }
}

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    map<pair<int, int>, vector<int>> m; // d,h
    get(root, m);
    int d = INT_MIN;
    int i = -1;
    for (auto &elem : m)
    {
        int currd = elem.first.first;
        int currh = elem.first.second;
        auto &v = elem.second;
        sort(v.begin(), v.end());
        if (currd == d)
        {
            auto &curr = ans.back();
            for (auto e : v)
            {
                curr.push_back(e);
            }
        }
        else
        {
            ans.push_back(v);
            d = currd;
        }
    }

    return ans;
}

int main()
{

    return 0;
}
