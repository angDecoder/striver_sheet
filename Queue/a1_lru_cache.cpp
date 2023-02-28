#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

class Node
{
public:
    int key, val;
    Node *next, *prev;

    Node(int k, int v)
    {
        key = k, val = v;
        next = prev = NULL;
    }
};

class LRUCache
{
public:
    int c;
    unordered_map<int, Node *> m;
    Node *head, *tail;

    LRUCache(int cap)
    {
        c = cap;
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (!m.count(key))
            return -1;

        // remove from current place
        Node *curr = m[key];
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        // insert just after the head
        curr->next = head->next;
        curr->prev = head;
        curr->prev->next = curr;
        curr->next->prev = curr;

        return curr->val;
    }

    void put(int key, int value)
    {
        if (m.count(key))
        {
            Node *curr = m[key];
            curr->val = value;
            get(key);
            return;
        }

        Node *curr = new Node(key, value);
        m[key] = curr;

        // insert just after the head;
        curr->next = head->next;
        curr->prev = head;
        curr->prev->next = curr;
        curr->next->prev = curr;

        if (m.size() <= c)
            return;

        // delete the least used key
        Node *temp = tail->prev;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        m.erase(temp->key);

        delete temp;
    }
};

int main()
{

    return 0;
}