#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

Node *merge(Node *h1, Node *h2)
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    Node *temp = new Node(0);
    Node *head = temp;
    while (h1 != NULL and h2 != NULL)
    {
        if (h1->data <= h2->data)
        {
            temp->child = h1;
            h1 = h1->child;
            temp = temp->child;
            temp->child = NULL;
        }
        else
        {
            temp->child = h2;
            h2 = h2->child;
            temp = temp->child;
            temp->child = NULL;
        }
    }
    if (h1 != NULL)
        temp->child = h1;
    else
        temp->child = h2;
    Node *ans = head->child;
    delete head;
    return ans;
}

Node *flattenLinkedList(Node *h1)
{
    if (h1 == NULL)
        return NULL;
        
    Node *h2 = flattenLinkedList(h1->next);

    return merge(h1, h2);
}

int main()
{

    return 0;
}