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

class BSTIterator
{
public:
    stack<TreeNode *> st;

    BSTIterator(TreeNode *root)
    {
        push(root);
    }

    int next()
    {
        auto *curr = st.top();
        st.pop();

        push(curr->right);

        return curr->val;
    }

    bool hasNext()
    {
        return (st.size() > 0);
    }

    void push(TreeNode *root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }
};

int main()
{

    return 0;
}