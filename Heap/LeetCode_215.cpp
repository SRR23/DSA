
// Given an integer array nums and an integer k, return the kth largest element
// in the array. Note that it is the kth largest element in the sorted order,
// not the kth distinct element. You must solve it in O(n) time complexity.

#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    vector<int> nodes;

    MaxHeap()
    {
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

    int printKthLargest(int k)
    {
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            ans = ExtractMax();
        }
        return ans;
    }
};

class Solution
{
public:
    int findKthLargest(vector<int> &a, int k)
    {
        MaxHeap heap;
        heap.build_from_array(a);
        int res = heap.printKthLargest(k);
        return res;
    }
};

int main()
{
    vector<int> a = {3, 2, 1, 5, 6, 4};
    int k;
    cin >> k;
    Solution s;
    cout << s.findKthLargest(a, k) << '\n';
    return 0;
}
