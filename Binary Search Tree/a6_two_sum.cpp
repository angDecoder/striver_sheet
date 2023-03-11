#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

template <typename T>
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
            delete left;
        if (right)
            delete right;
    }
};

class BSTIterator
{
public:
    stack<BinaryTreeNode<int> *> front, back;

    BSTIterator(BinaryTreeNode<int> *root)
    {
        pushNext(root);
        pushPrev(root);
    }

    void pushNext(BinaryTreeNode<int> *root)
    {
        while (root)
        {
            front.push(root);
            root = root->left;
        }
    }

    void pushPrev(BinaryTreeNode<int> *root)
    {
        while (root)
        {
            back.push(root);
            root = root->right;
        }
    }

    int next()
    {
        auto *curr = front.top();
        front.pop();
        pushNext(curr->right);

        return curr->data;
    }

    int prev()
    {
        auto *curr = back.top();
        back.pop();
        pushPrev(curr->left);

        return curr->data;
    }

    bool isEmpty()
    {
        return front.empty() or back.empty();
    }
};

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    BSTIterator it(root);
    int next = it.next(), prev = it.prev();

    do
    {
        int sum = next + prev;
        if (sum == k)
            return true;
        else if (sum > k)
            prev = it.prev();
        else
            next = it.next();

    } while (!it.isEmpty());

    return false;
}

int main()
{

    return 0;
}