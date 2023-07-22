#include <bits/stdc++.h>
using namespace std;

// https://www.alphacodingskills.com/cpp/ds/cpp-linked-list.php
class node
{
public:
    int data;
    node *nxt;
};

class linked_list
{
public:
    node *head;
    node *tail;
    int sz;
    linked_list()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }
    node *CreateNewNode(int value)
    {
        node *NewNode = new node;
        NewNode->data = value;
        NewNode->nxt = NULL;
        return NewNode;
    }

    // O(1)
    void InsertAtHead(int value)
    {
        sz++;
        node *a = CreateNewNode(value);
        if (head == NULL)
        {
            head = a;
            tail = a;
            return;
        }
        a->nxt = head;
        head = a;
    }

    // O(1)
    void InsertAtEnd(int value)
    {
        sz++;
        node *a = CreateNewNode(value);
        tail->nxt = a;
        tail = a;
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
    // Return the value from the given index
    int get_value(int idx)
    {
        if (idx >= sz)
        {
            return -1;
        }
        node *a = head;
        int cnt = 0;
        while (a != NULL)
        {
            if (cnt == idx)
            {
                return a->data;
            }
            cnt++;
            a = a->nxt;
        }
    }
    // Return the index from the given value
    int get_index(int value)
    {
        node *a = head;
        int index = 0;
        while (a != NULL)
        {
            if (a->data == value)
            {
                return index;
            }
            index++;
            a = a->nxt;
        }
        return -1;
    }
    // Count how many times a value exist
    void Occurrence_Of_Value(int value)
    {
        node *a = head;
        int cnt = 0;
        while (a != NULL)
        {
            if (a->data == value)
            {
                cnt++;
            }
            a = a->nxt;
        }
        cout << cnt << '\n';
    }
    // insert element at any index
    void InsertAtAnyIndex(int idx, int value)
    {
        if (idx < 0 && idx > sz)
        {
            return;
        }
        sz++;
        if (idx == 0)
        {
            InsertAtHead(value);
        }
        node *a = head;
        int cur_indx = 0;
        while (cur_indx != (idx - 1))
        {
            cur_indx++;
            a = a->nxt;
        }
        node *NewNode = CreateNewNode(value);
        NewNode->nxt = a->nxt;
        a->nxt = NewNode;
    }
    // delete from head
    void DeleteAtHead()
    {
        sz--;
        if (head == NULL)
        {
            return;
        }
        node *a = head;
        head = a->nxt;
        delete a;
    }
    // delete element at any index
    void DeleteAnyIndex(int index)
    {
        if (index < 0 || index > sz - 1)
        {
            return;
        }
        if (index == 0)
        {
            DeleteAtHead();
            return;
        }
        sz--;
        node *a = head;
        int cur_index = 0;
        while (cur_index != index - 1)
        {
            a = a->nxt;
            cur_index++;
        }
        node *b = a->nxt;
        a->nxt = b->nxt;
        delete b;
    }
    void InsertAfterValue(int value, int data)
    {
        node *a = head;
        while (a != NULL)
        {
            if (a->data == value)
            {
                break;
            }
            a = a->nxt;
        }
        if (a == NULL)
        {
            cout << value << " doesn't exist in linked-list.\n";
            return;
        }
        sz++;
        node *newnode = CreateNewNode(data);
        newnode->nxt = a->nxt;
        a->nxt = newnode;
    }
    // Reverse the linked-list
    void Reverse(node *a)
    {
        if (a == NULL)
        {
            return;
        }
        Reverse(a->nxt);
        cout << a->data << " ";
    }
    // Print Reverse linked-list
    void Print_Reverse()
    {
        Reverse(head);
        cout << '\n';
    }
};

int main()
{
    linked_list l;
    l.InsertAtHead(50);
    l.InsertAtHead(40);
    l.InsertAtHead(10);
    l.InsertAtHead(20);
    l.InsertAtHead(10);
    l.InsertAtHead(10);
    l.InsertAtHead(10);
    l.InsertAtEnd(100);
    l.InsertAtEnd(200);
    cout << l.get_size() << '\n';
    l.Traverse();
    // cout << l.get_value(2) << '\n';
    // l.Print_Reverse();
    // cout << l.get_index(60) << '\n';
    // l.Occurrence_Of_Value(10);
    // l.InsertAtAnyIndex(2, 20);
    // cout << l.get_size() << '\n';
    // l.Traverse();
    // l.DeleteAtHead();
    // cout << l.get_size() << '\n';
    // l.Traverse();
    return 0;
}