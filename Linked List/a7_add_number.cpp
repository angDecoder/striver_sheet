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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    // l1 = reverseList( l1 );
    // l2 = reverseList(l2);
    int c = 0;
    ListNode *head = NULL;
    ListNode *temp = head;

    while (l1 != NULL and l2 != NULL)
    {
        int val = c + l1->val + l2->val;
        c = val / 10;
        val = val % 10;
        if (head == NULL)
        {
            head = new ListNode(val);
            temp = head;
        }
        else
        {
            temp->next = new ListNode(val);
            temp = temp->next;
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    if (l1 == NULL)
        swap(l1, l2);

    while (l1 != NULL)
    {
        int val = c + l1->val;
        c = val / 10;
        val = val % 10;

        if (head == NULL)
        {
            head = new ListNode(val);
            temp = head;
        }
        else
        {
            temp->next = new ListNode(val);
            temp = temp->next;
        }
        l1 = l1->next;
    }
    if (c)
    {
        temp->next = new ListNode(c);
    }

    return head;
}

int main()
{

    return 0;
}