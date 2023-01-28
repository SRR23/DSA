#include <bits/stdc++.h>
using namespace std;

class Array
{
private:
    int *arr;
    int cap;
    int sz;

    void increase_size()
    {
        cap = cap * 2;
        int *temp = new int[cap];
        for (int i = 0; i < sz; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }

public:
    Array()
    {
        arr = new int[1];
        cap = 1;
        sz = 0;
    }
    void push(int x)
    {
        if (cap == sz)
        {
            increase_size();
        }
        arr[sz] = x;
        sz++;
    }
    void print()
    {
        for (int i = 0; i < sz; i++)
        {
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
    int get_size()
    {
        return sz;
    }
    int get_element(int idx)
    {
        if (idx >= sz)
        {
            cout << "Error,"
                 << " " << idx << " is out of bound" << '\n';
            return -1;
        }
        return arr[idx];
    }
    void Insert(int pos, int x)
    {
        if (cap == sz)
        {
            increase_size();
        }
        for (int i = sz - 1; i >= pos; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[pos] = x;
        sz++;
    }
    void Pop_back()
    {
        if (sz == 0)
        {
            cout << "Current Size is zero\n";
            return;
        }
        sz--;
    }
    void Erase(int pos)
    {
        if (pos >= sz)
        {
            cout << "Position doesn't exist\n";
            return;
        }
        for (int i = pos + 1; i < sz; i++)
        {
            arr[i - 1] = arr[i];
        }
        sz--;
    }
};

int main()
{
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Array a;
    a.push(10);
    a.push(20);
    a.push(30);
    a.push(40);
    a.push(50);
    //    a.Insert(1,15);

    //    a.Pop_back();
    a.Erase(1);
    a.print();

    //    cout<<a.get_size()<<'\n';
    //    cout<<a.get_element(4);
}
