#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next){}
                                                  
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        if (list2->val < list1->val)
            swap(list1, list2);

        ListNode *temp1 = list1->next;
        ListNode *temp2 = list2;
        ListNode *prev = list1;
        while (temp1 != NULL and temp2 != NULL)
        {
            if (temp1->val <= temp2->val)
            {
                temp1 = temp1->next;
                prev = prev->next;
            }
            else
            {
                ListNode *t = temp2;
                temp2 = temp2->next;
                prev->next = t;
                t->next = temp1;
                prev = prev->next;
            }
        }

        if (temp2 != NULL)
        {
            prev->next = temp2;
        }

        return list1;
    }
};

int main()
{

    return 0;
}