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

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *end = head;
    ListNode *prev = head;
    if (k == 1)
        return head;
    bool done = false;
    while (end != NULL)
    {
        int cnt = 1;
        ListNode *start = end;
        while (cnt <= k and end != NULL)
        {
            end = end->next;
            cnt++;
        }
        if (cnt <= k)
            return head;

        ListNode *t1 = start;
        ListNode *t2 = t1->next;
        ListNode *t3 = t2->next;

        while (t2 != end)
        {
            t2->next = t1;
            t1 = t2;
            t2 = t3;
            if (t3)
                t3 = t3->next;
        }

        if (!done)
        {
            done = true;
            head = t1;
        }
        prev->next = t1;
        start->next = end;
        prev = start;
    }

    return head;
}

int main()
{

    return 0;
}