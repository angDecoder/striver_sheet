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

ListNode *detectCycle(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    do
    {
        if (fast == NULL or fast->next == NULL)
            return NULL;
        fast = fast->next->next;
        slow = slow->next;
    } while (fast != slow);

    fast = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

bool hasCycle(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    do
    {
        if (fast == NULL or fast->next == NULL)
            return false;
        fast = fast->next->next;
        slow = slow->next;
    } while (fast != slow);

    return true;
}

int main()
{

    return 0;
}