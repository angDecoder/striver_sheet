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

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string ans = "";
        if (root == NULL)
            return "n";

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            auto *curr = q.front();
            q.pop();

            if (curr == NULL)
                ans += " n";
            else
            {
                ans += " " + to_string(curr->val);
                q.push(curr->left);
                q.push(curr->right);
            }
        }

        return ans;
    }

    int getNext(string &s, int &i)
    {
        while (i < s.size() and s[i] == ' ')
            i++;
        if (i >= s.size() or s[i] == 'n')
        {
            i++;
            return 1001;
        }

        bool neg = false;
        if (s[i] == '-')
        {
            neg = true;
            i++;
        }

        int num = 0;
        while (i < s.size() and s[i] != ' ')
        {
            int n = s[i] - '0';
            num = num * 10 + n;
            i++;
        }
        if (neg)
            num = -num;
        return num;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string s)
    {
        int i = 0;
        int n = getNext(s, i);
        if (n == 1001)
            return NULL;

        queue<TreeNode *> q;
        TreeNode *root = new TreeNode(n);
        q.push(root);
        while (q.size())
        {
            auto *curr = q.front();
            q.pop();
            int num1 = getNext(s, i);
            int num2 = getNext(s, i);

            TreeNode *left = NULL, *right = NULL;
            if (num1 != 1001)
            {
                left = new TreeNode(num1);
                q.push(left);
            }

            if (num2 != 1001)
            {
                right = new TreeNode(num2);
                q.push(right);
            }

            curr->left = left;
            curr->right = right;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main()
{

    return 0;
}