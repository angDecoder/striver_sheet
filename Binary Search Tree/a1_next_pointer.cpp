#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return NULL;

        queue<Node *> q;
        q.push(root);

        int s = 2;
        while (!q.empty())
        {
            auto *curr = q.front();
            q.pop();

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);

            if (q.size() == s)
            {
                s = s * 2;
                queue<Node *> temp;
                while (!q.empty())
                {
                    auto *curr = q.front();
                    q.pop();

                    if (q.size())
                    {
                        curr->next = q.front();
                    }

                    temp.push(curr);
                }

                while (!temp.empty())
                {
                    auto *curr = temp.front();
                    temp.pop();

                    q.push(curr);
                }
            }
        }

        return root;
    }
};

int main()
{

    return 0;
}