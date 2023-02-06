#include <bits/stdc++.h>
using namespace std;
const int N = 500;
class Queue
{
public:
    int a[N];
    int l, r;
    int sz;
    Queue()
    {
        l = 0;
        r = -1;
        sz = 0;
    }

    void enqueue(int value)
    {
        if (sz == N)
        {
            cout << "Queue is full!\n";
            return;
        }
        r++;
        if (r == N)
        {
            r = 0;
        }
        a[r] = value;
        sz++;
    }

    void dequeue()
    {
        if (sz == 0)
        {
            cout << "Queue is empty\n";
            return;
        }
        l++;
        if (l == N)
        {
            l = 0;
        }
        sz--;
    }

    int front()
    {
        if (sz == 0)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return a[l];
    }

    int size()
    {
        return sz;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    cout << q.size() << '\n';

    cout << q.front() << '\n';
    q.dequeue();

    cout << q.front() << '\n';
    q.dequeue();

    cout << q.front() << '\n';
    q.dequeue();

    cout << q.size() << '\n';
}