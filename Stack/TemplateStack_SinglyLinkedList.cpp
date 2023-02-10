#include <bits/stdc++.h>
using namespace std;

template <class T>
class node
{
public:
    T data;
    node *nxt;
};

template <class T>
class SinglyLinkedList
{
public:
    node<T> *head;
    int sz;
    SinglyLinkedList()
    {
        head = NULL;
        sz = 0;
    }

    // Creates a new node with the given data and returns it O(1)
    node<T> *CreateNewNode(T data)
    {
        node<T> *newnode = new node<T>;
        newnode->data = data;
        newnode->nxt = NULL;
        return newnode;
    }

    // Inserts a node with given data at head O(1)
    void InsertAtHead(T data)
    {
        sz++;
        node<T> *a = CreateNewNode(data);
        if (head == NULL)
        {
            head = a;
            return;
        }
        a->nxt = head;
        head = a;
    }
    // Deletes the value at head. O(1)
    void DeleteAtHead()
    {
        sz--;
        if (head == NULL)
        {
            return;
        }
        node<T> *a = head;
        head = a->nxt;
        delete a;
    }
    // Returns the size of linked list O(1)
    int getSize()
    {
        return sz;
    }
};

// Stack using doubly linked list
template <class T>
class Stack
{
public:
    SinglyLinkedList<T> l;

    Stack()
    {
    }

    T top()
    {
        if (l.getSize() == 0)
        {
            cout << "Stack is empty!\n";
            T a;
            return a;
        }
        return l.head->data;
    }

    void push(T val)
    {
        l.InsertAtHead(val);
    }

    void pop()
    {
        if (l.getSize() == 0)
        {
            cout << "Stack is empty!\n";
            return;
        }
        l.DeleteAtHead();
    }
};

int main()
{
    Stack<double> st;
    st.push(3.5);
    st.push(3.6);
    st.push(7.8);
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";

    Stack<char> st2;
    st2.push('a');
    st2.push('g');
    st2.push('u');
    cout << st2.top() << "\n";
    st2.pop();
    cout << st2.top() << "\n";
    st2.pop();
    cout << st2.top() << "\n";
    st2.pop();
    cout << st2.top() << "\n";
    return 0;
}