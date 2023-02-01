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

ListNode *getIntersectionNode(ListNode *h1, ListNode *h2)
{
    if (h1 == NULL or h2 == NULL)
        return NULL;
    ListNode *t1 = h1, *t2 = h2;
    while (t1 != t2)
    {
        t1 = t1 == NULL ? h2 : t1->next;
        t2 = t2 == NULL ? h1 : t2->next;
    }

    return t1;
}

int main()
{

    return 0;
}