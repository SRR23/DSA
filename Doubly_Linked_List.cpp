#include <bits/stdc++.h>
using namespace std;

// https://www.alphacodingskills.com/cpp/ds/cpp-doubly-linked-list.php
class node
{
public:
    int data;
    node *nxt;
    node *prev;
};

class DoublyLinkedList
{
public:
    node *head;
    int sz;
    DoublyLinkedList()
    {
        head = NULL;
        sz = 0;
    }
    node *CreateNewNode(int value)
    {
        node *NewNode = new node;
        NewNode->data = value;
        NewNode->nxt = NULL;
        NewNode->prev = NULL;
        return NewNode;
    }
    void InsertAtHead(int value)
    {
        sz++;
        node *NewNode = CreateNewNode(value);
        if (head == NULL)
        {
            head = NewNode;
            return;
        }
        node *a = head;
        NewNode->nxt = a;
        a->prev = NewNode;
        head = NewNode;
    }
    void Traverse()
    {
        node *a = head;
        while (a != NULL)
        {
            cout << a->data << " ";
            a = a->nxt;
        }
        cout << '\n';
    }
    int get_size()
    {
        return sz;
    }
    void InsertAtAnyIndex(int indx, int value)
    {
        if (indx < 0 && indx > sz)
        {
            return;
        }
        if (indx == 0)
        {
            InsertAtHead(value);
            return;
        }
        node *a = head;
        int cur_indx = 0;
        while (cur_indx != (indx - 1))
        {
            cur_indx++;
            a = a->nxt;
        }
        node *NewNode = CreateNewNode(value);
        NewNode->nxt = a->nxt;
        NewNode->prev = a;
        node *b = a->nxt;
        b->prev = NewNode;
        a->nxt = NewNode;
        sz++;
    }
    void Delete(int index)
    {
        if (index >= sz)
        {
            cout << index << " doesn't exist.\n";
            return;
        }
        node *a = head;
        int cur_index = 0;
        while (cur_index != index)
        {
            a = a->nxt;
            cur_index++;
        }
        node *b = a->prev;
        node *c = a->nxt;
        if (b != NULL)
        {
            b->nxt = c;
        }
        if (c != NULL)
        {
            c->prev = b;
        }
        delete a;
        if (index == 0)
        {
            head = c;
        }
        sz--;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    DoublyLinkedList dl;
    dl.InsertAtHead(50);
    dl.InsertAtHead(40);
    dl.InsertAtHead(30);
    dl.InsertAtHead(20);
    dl.InsertAtHead(10);
    dl.Traverse();
    dl.InsertAtAnyIndex(2, 50);
    dl.Traverse();
    dl.Delete(4);
    dl.Traverse();
}