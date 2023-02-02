#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *h1)
    {
        if (h1 == NULL)
            return NULL;

        Node *h2 = new Node(h1->val);
        h1->next = h2, h2->random = h1;

        Node *t1 = h1->next, *t2 = h2;

        while( t1 ){
            Node *temp = t1;
            t1 = t1->next;

            t2->next = new Node(temp->val);
            t2 = t2->next;
            t2->random = temp;
            temp->next = t2;
        }

        t2 = h2;
        while( t2 ){
            t1 = t2->random;
            t2->random = t2->random->random->next;

            if( t2->next )
                t1->next = t2->next->random;
            else 
                t1->next = NULL;
        }

        return h2;
    }
};

int main()
{

    return 0;
}