#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

class Node
{
public:
    int size, minval, maxval;

    Node(int s, int minv, int maxv)
    {
        size = s;
        minval = minv, maxval = maxv;
    }
};

bool isValid(TreeNode<int> *root, Node &left, Node &right)
{
    return root->data > left.maxval and root->data < right.minval;
}

Node find(TreeNode<int> *root)
{
    if (root == NULL)
        return Node(0, INT_MAX, INT_MIN);

    Node left = find(root->left);
    Node right = find(root->right);

    if (isValid(root, left, right))
    {
        int size = left.size + right.size;
        int minv = min(left.minval, root->data);
        int maxv = max(right.maxval, root->data);

        return Node(size + 1, minv, maxv);
    }

    int size = max(left.size, right.size);
    return Node(size, INT_MIN, INT_MAX);
}

int largestBST(TreeNode<int> *root)
{
    return find(root).size;
}

int main()
{

    return 0;
}