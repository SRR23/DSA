#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *nxt;
};

class LinkedList
{
public:
    node *head;
    LinkedList()
    {
        head = NULL;
    }

    node *CreateNewNode(int value)
    {
        node *NewNode = new node;
        NewNode->data = value;
        NewNode->nxt = NULL;
        return NewNode;
    }

    void InsertAtHead(int value)
    {
        node *a = CreateNewNode(value);
        if (head == NULL)
        {
            head = a;
            return;
        }
        a->nxt = head;
        head = a;
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
};

int main()
{
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    LinkedList a;
    a.InsertAtHead(10);
    a.InsertAtHead(20);
    a.InsertAtHead(30);
    a.InsertAtHead(40);

    a.Traverse();
}

/*
#include<bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node * nxt;
};

class LinkedList
{
public:
    node * head;
    int sz;
    LinkedList()
    {
        head = NULL;
        sz=0;
    }

    node* CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->nxt = NULL;
        return newnode;
    }

    void InsertAtHead(int value)
    {
        sz++;
        node *a = CreateNewNode(value);
        if(head == NULL)
        {
            head = a;
            return;
        }
        a->nxt = head;
        head = a;
    }

    void Traverse()
    {
        node* a = head;
        while(a!= NULL)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<"\n";
    }

    int getSize()
    {
        return sz;
    }

    int getValue(int indx)
    {
        if(indx>=sz)
        {
            return -1;
        }

        node *a = head;
        int cnt = 0;
        while(a != NULL)
        {
            if(cnt == indx)
            {
                return a->data;
            }
            cnt++;
            a = a->nxt;
        }
    }


    void printReverse(node* head)
    {
        if (head == NULL)
        {
            return;
        }
        printReverse(head->nxt);
        cout << head->data << " ";
    }

    void swapFirst()
    {
        node *a = head;
        while(a != NULL && a->nxt != NULL)
        {
            swap(a->data, a->nxt->data);
            break;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    LinkedList l;
    cout<<l.getSize()<<"\n";
    l.InsertAtHead(5);
    cout<<l.getSize()<<"\n";

    l.InsertAtHead(6);
    l.InsertAtHead(30);
    cout<<l.getSize()<<"\n";
    l.InsertAtHead(20);
    l.InsertAtHead(30);

    cout<<l.getValue(2)<<"\n";

    cout<<l.getValue(6)<<"\n";

    l.printReverse(l.head);
    cout<<'\n';
    l.Traverse();
    l.swapFirst();
    l.Traverse();
    l.printReverse(l.head);

    return 0;
}
*/