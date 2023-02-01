#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void deleteNode(ListNode *node)
{
    if (node == NULL)
        return;

    node->val = node->next->val;
    node->next = node->next->next;
}

int main()
{

    return 0;
}