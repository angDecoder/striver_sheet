#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

#include <bits/stdc++.h>

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
};
void getLeft(TreeNode<int> *root, int h, map<int, int> &m)
{
    if (root == NULL)
        return;

    m[h] = root->data;
    getLeft(root->right, h + 1, m);
    getLeft(root->left, h + 1, m);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    map<int, int> m;
    vector<int> ans;
    getLeft(root, 0, m);

    for (auto &elem : m)
    {
        ans.push_back(elem.second);
    }

    return ans;
}

int main()
{
    queue<int> q;
    

    return 0;
}