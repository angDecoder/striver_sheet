#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

int findCeil(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
        return -1;

    if (root->data >= x)
    {
        int res = findCeil(root->left, x);
        if (res == -1)
            return root->data;

        return res;
    }
    return findCeil(root->right, x);
}

int main()
{

    return 0;
}