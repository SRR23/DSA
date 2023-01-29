#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int *a;
    int sz;
    int cap;
    Stack()
    {
        sz = 0;
        a = new int[1];
        cap = 1;
    }
    void Increase_Size()
    {
        int *tmp;
        tmp = new int[cap * 2];
        for (int i = 0; i < cap; i++)
        {
            tmp[i] = a[i];
        }
        swap(a, tmp);
        delete[] tmp;
        cap *= 2;
    }
    void Push(int value)
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
        a[sz - 1] = 0;
        sz--;
    }
    int Top()
    {
        if (sz == 0)
        {
            cout << "Stack is empty!\n";
            return -1;
        }
        return a[sz - 1];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Stack st;
    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Push(40);
    st.Push(50);
    cout << st.Top() << '\n';
    st.Pop();
    cout << st.Top() << '\n';
}