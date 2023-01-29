#include <bits/stdc++.h>
using namespace std;
const int N = 500;
class Stack
{
public:
    int a[N];
    int sz;
    Stack()
    {
        sz = 0;
    }
    void Push(int value)
    {
        if (sz + 1 > N)
        {
            cout << "Error! Stack is full\n";
            return;
        }
        sz++;
        a[sz - 1] = value;
    }
    void Pop()
    {
        if (sz == 0)
        {
            cout << "Stack is empty\n";
            return;
        }
        a[sz - 1] = 0;
        sz--;
    }
    int Top()
    {
        if (sz == 0)
        {
            cout << "Stack is empty\n";
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