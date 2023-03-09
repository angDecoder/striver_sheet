#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Function to convert a binary tree into its mirror tree.
Node *build(Node *root)
{
    if (root == NULL)
        return NULL;

    auto *left = build(root->left);
    auto *right = build(root->right);

    root->left = right;
    root->right = left;
}

void mirror(Node *node)
{
    build(node);
}

int main()
{

    return 0;
}