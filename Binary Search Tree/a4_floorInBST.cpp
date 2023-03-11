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

int floorInBST(TreeNode<int> *root, int key)
{
    if (root == NULL)
        return INT_MIN;

    if (root->val > key)
        return floorInBST(root->left, key);
    if (root->val <= key)
        return max(root->val, floorInBST(root->right, key));
}

int main()
{

    return 0;
}