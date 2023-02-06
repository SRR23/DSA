#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int *a;
    int l, r;
    int sz;
    int cap;
    Queue()
    {
        a = new int[1];
        cap = 1;
        l = 0;
        r = -1;
        sz = 0;
    }

    void remove_circular()
    {
        if (l > r)
        {
            int *tmp = new int[cap];
            int idx = 0;
            for (int i = l; i < cap; i++)
            {
                tmp[idx] = a[i];
                idx++;
            }
            for (int i = 0; i <= r; i++)
            {
                tmp[idx] = a[i];
                idx++;
            }
            swap(tmp, a);
            l = 0;
            r = cap - 1;
            delete[] tmp;
        }
    }

    void increase_size()
    {
        remove_circular();
        int *tmp = new int[cap * 2];
        for (int i = 0; i < cap; i++)
        {
            tmp[i] = a[i];
        }
        swap(a, tmp);
        cap *= 2;
        delete[] tmp;
    }

    void enqueue(int value)
    {
        if (sz == cap)
        {
            increase_size();
        }
        r++;
        if (r == cap)
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
        if (l == cap)
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