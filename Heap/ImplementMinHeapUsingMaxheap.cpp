#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    vector<int> nodes;

    MaxHeap()
    {
    }

    void up_heapify(int indx)
    {
        while (indx > 0 && nodes[indx] > nodes[(indx - 1) / 2])
        {
            swap(nodes[indx], nodes[(indx - 1) / 2]);
            indx = (indx - 1) / 2;
        }
    }
    void Insert(int value)
    {
        nodes.push_back(value);
        up_heapify(nodes.size() - 1);
    }

    void Print_Heap()
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            cout << abs(nodes[i]) << " ";
        }
        cout << '\n';
    }

    void down_heapify(int indx)
    {
        while (1)
        {
            int largest = indx;
            int l = 2 * indx + 1;
            int r = 2 * indx + 2;
            if (l < nodes.size() && nodes[largest] < nodes[l])
            {
                largest = l;
            }
            if (r < nodes.size() && nodes[largest] < nodes[r])
            {
                largest = r;
            }
            if (largest == indx)
            {
                break;
            }
            swap(nodes[indx], nodes[largest]);
            indx = largest;
        }
    }

    void DElete(int indx)
    {
        if (indx >= nodes.size())
        {
            return;
        }
        swap(nodes[indx], nodes[nodes.size() - 1]);
        nodes.pop_back();
        down_heapify(indx);
    }

    int getMax()
    {
        if (nodes.empty())
        {
            cout << "Heap is empty\n";
            return -1;
        }
        return nodes[0];
    }
};

class MinHeap
{
public:
    MaxHeap mx;
    void insert(int x)
    {
        mx.Insert(-x);
    }
    void Delete(int idx)
    {
        mx.DElete(idx);
    }
    int getMin()
    {
        return -mx.getMax();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    MinHeap heap;
    MaxHeap mx;

    mx.Insert(7);
    mx.Insert(5);
    mx.Insert(9);
    mx.Insert(10);
    mx.Insert(4);
    mx.Insert(3);
    mx.Insert(2);
    mx.Insert(1);

    cout<<"Print MaxHeap : ";
    mx.Print_Heap();

    heap.insert(7);
    heap.insert(5);
    heap.insert(9);
    heap.insert(10);
    heap.insert(4);
    heap.insert(3);
    heap.insert(2);
    heap.insert(1);

    cout<<"Print MinHeap : ";
    heap.mx.Print_Heap();

    cout<<"After deleting root element, MinHeap is : ";
    heap.Delete(0);
    heap.mx.Print_Heap();

    return 0;
}
