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
            cout << nodes[i] << " ";
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

    void Delete(int indx)
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

    int ExtractMax()
    {
        if (nodes.empty())
        {
            cout << "Heap is empty\n";
            return -1;
        }
        int m = nodes[0];
        Delete(0);
        return m;
    }

    void build_from_array(vector<int> &a)
    {
        nodes = a;
        int n = nodes.size();
        int last_non_leaf = n / 2 - 1;
        for (int i = last_non_leaf; i >= 0; i--)
        {
            down_heapify(i);
        }
    }
};

int main()
{
    MaxHeap heap;
    vector<int> a = {1, 2, 3, 4, 10, 9, 8, 7};
    heap.build_from_array(a);
    heap.Print_Heap();
}