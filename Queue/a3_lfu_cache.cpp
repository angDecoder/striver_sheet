#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

class Node
{
public:
    int freq, val, key;
    Node *next, *prev;

    Node(int f, int v, int k)
    {
        freq = f, val = v, key = k;
        next = prev = NULL;
    }
};

class LFUCache
{
public:
    int c;
    map<int, pair<Node *, Node *>> freq;
    map<int, Node *> m;
    LFUCache(int cap)
    {
        c = cap;
    }

    void deleteFreq(int f)
    {
        if (freq.count(f) == 0)
            return;

        auto pr = freq[f];
        Node *head = pr.first;
        Node *tail = pr.second;

        if (head->next == tail)
        {
            freq.erase(f);
            delete head;
            delete tail;
        }
    }

    void createFreq(int f)
    {
        if (freq.count(f))
            return;

        Node *head = new Node(f, 0, 0);
        Node *tail = new Node(f, 0, 0);
        head->next = tail;
        tail->prev = head;

        freq[f] = {head, tail};
    }

    int get(int key)
    {
        // if not present return -1;
        if (m.count(key) == 0)
            return -1;

        Node *curr = m[key];
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        int f = curr->freq;
        curr->freq++;
        deleteFreq(f);

        createFreq(f + 1);
        Node *head = freq[f + 1].first;
        curr->next = head->next;
        curr->prev = head;
        curr->next->prev = curr;
        curr->prev->next = curr;

        return curr->val;
        /* if key is present
            -done 1. remove from prev frequency
                -> remove
                -> if list is empty delete the list
            -done 2. add the node to new list
                -> if new freq not present then create list
                -> add to front of the list;
            3. return the value
        */
    }

    void put(int key, int value)
    {
        // if key already present then update and get the value;
        if (m.count(key))
        {
            Node *curr = m[key];
            curr->val = value;
            get(key);

            return;
        }

        Node *curr = new Node(1, value, key);
        m[key] = curr;
        if (m.size() > c)
        {
            auto it = freq.begin();
            auto pr = it->second;
            Node *temp = pr.second->prev;
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            m.erase(temp->key);
            deleteFreq(temp->freq);
            delete temp;
        }

        createFreq(1);
        auto pr = freq[1];
        Node *head = pr.first;
        curr->next = head->next;
        curr->prev = head;
        curr->next->prev = curr;
        curr->prev->next = curr;

        /* if key is not present
            1. create a new node with key and value
            2. if the size is equal to capacity then delete lowest freqency node
            3. add the curr node to freq list of 1

        */
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    queue<vector<int>> q;
    

    return 0;
}