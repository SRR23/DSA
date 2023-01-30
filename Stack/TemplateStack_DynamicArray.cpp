#include <bits/stdc++.h>
using namespace std;

template <class T>
class Stack
{
public:
    T *a;
    int sz;
    int cap;
    Stack()
    {
        sz = 0;
        a = new T[1];
        cap = 1;
    }
    void Increase_Size()
    {
        T *tmp;
        tmp = new T[cap * 2];
        for (int i = 0; i < cap; i++)
        {
            tmp[i] = a[i];
        }
        swap(a, tmp);
        delete[] tmp;
        cap *= 2;
    }
    void Push(T value)
    {
        if (sz + 1 > cap)
        {
            Increase_Size();
        }
        sz++;
        a[sz - 1] = value;
    }
    void Pop()
    {
        if (sz == 0)
        {
            cout << "Stack is empty!\n";
            return;
        }
        sz--;
    }
    T Top()
    {
        if (sz == 0)
        {
            cout << "Stack is empty!\n";
            T a;
            return a;
        }
        return a[sz - 1];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Stack<int> st;
    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Push(40);
    st.Push(50);
    cout << st.Top() << '\n';
    st.Pop();
    cout << st.Top() << '\n';

    Stack<char> st2;
    st2.Push('a');
    st2.Push('g');
    st2.Push('u');
    cout << st2.Top() << "\n";
    st2.Pop();
    cout << st2.Top() << "\n";
    st2.Pop();
    cout << st2.Top() << "\n";
    st2.Pop();
    cout << st2.Top() << "\n";
}