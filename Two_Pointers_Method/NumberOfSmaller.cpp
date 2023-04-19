
// You are given two arrays, sorted in non-decreasing order. For
// each element of the second array, find the number of elements
// in the first array strictly less than it

// if array is unsorted then first sort the array.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int b[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    int j = 0;
    vector<int> v;
    for (int i = 0; i < m; i++)
    {
        while (j < n && a[j] < b[i])
        {
            j++;
        }
        v.push_back(j);
    }
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << '\n';
}