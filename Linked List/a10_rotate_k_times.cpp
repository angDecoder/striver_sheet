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

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    int cnt = 0;
    ListNode *t1 = head;
    while (t1)
    {
        t1 = t1->next;
        cnt++;
    }
    k = k % cnt;
    if (k == 0)
        return head;

    t1 = head;
    ListNode *t2 = head;

    while (t2->next)
    {
        t2 = t2->next;
    }
    t2->next = head;

    for (int i = 1; i < (cnt - k); i++)
    {
        t1 = t1->next;
    }
    head = t1->next;
    t1->next = NULL;

    return head;
}

int main()
{

    return 0;
}