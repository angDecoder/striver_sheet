#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void get(TreeNode<int> *root, map<int, int> &m)
{
    if (root == NULL)
        return;

    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto &curr = q.front();
        auto *node = curr.first;
        int d = curr.second;
        q.pop();

        if (m.count(d) == 0)
            m[d] = node->val;

        if (node->left)
            q.push({node->left, d - 1});
        if (node->right)
            q.push({node->right, d + 1});
    }
}

vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> ans;
    map<int, int> m;
    get(root, m);
    for (auto elem : m)
    {
        ans.push_back(elem.second);
    }

    return ans;
}

int main()
{

    return 0;
}