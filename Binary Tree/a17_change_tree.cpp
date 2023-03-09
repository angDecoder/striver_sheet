#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void changeTree(BinaryTreeNode *root)
{
    if (root == NULL)
        return;

    int child = 0;
    if (root->left)
    {
        root->left->data = max(root->data, root->left->data);
        child += root->left->data;
    }

    if (root->right)
    {
        root->right->data = max(root->data, root->right->data);
        child += root->right->data;
    }

    root->data = max(root->data, child);
    changeTree(root->left);
    changeTree(root->right);

    int sum = 0;
    if (root->right)
        sum += root->right->data;
    if (root->left)
        sum += root->left->data;

    if (root->right or root->left)
        root->data = sum;

    // return root->data + right + left;
}

int main()
{

    return 0;
}