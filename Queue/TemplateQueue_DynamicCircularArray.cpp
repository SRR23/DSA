#include <bits/stdc++.h>
using namespace std;

template <class T>
class Queue
{
public:
    T *a;
    int l, r;
    int sz;
    int cap;
    Queue()
    {
        a = new T[1];
        cap = 1;
        l = 0;
        r = -1;
        sz = 0;
    }

    void remove_circular()
    {
        if (l > r)
        {
            T *tmp = new T[cap];
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
        T *tmp = new T[cap * 2];
        for (int i = 0; i < cap; i++)
        {
            tmp[i] = a[i];
        }
        swap(a, tmp);
        cap *= 2;
        delete[] tmp;
    }

    void enqueue(T value)
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

    T front()
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

    Queue<int> q;
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

    Queue<double> q2;
    q2.enqueue(5.60);
    q2.enqueue(6.40);
    q2.enqueue(7.50);

    cout << q2.size() << '\n';

    cout << q2.front() << '\n';
    q2.dequeue();

    cout << q2.front() << '\n';
    q2.dequeue();

    cout << q2.front() << '\n';
    q2.dequeue();

    cout << q2.size() << '\n';
}