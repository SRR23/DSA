#include <bits/stdc++.h>
using namespace std;

vector<int> merge_sort(vector<int> a)
{
    if (a.size() <= 1)
    {
        return a;
    }

    int mid = a.size() / 2;
    vector<int> b;
    vector<int> c;
    for (int i = 0; i < mid; i++)
    {
        b.push_back(a[i]);
    }
    for (int i = mid; i < a.size(); i++)
    {
        c.push_back(a[i]);
    }

    vector<int> sorted_b = merge_sort(b);
    vector<int> sorted_c = merge_sort(c);

    vector<int> sorted_a;
    int indx1 = 0, indx2 = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (indx1 == sorted_b.size())
        {
            sorted_a.push_back(sorted_c[indx2]);
            indx2++;
        }
        else if (indx2 == sorted_c.size())
        {
            sorted_a.push_back(sorted_b[indx1]);
            indx1++;
        }
        else if (sorted_b[indx1] < sorted_c[indx2])
        {
            sorted_a.push_back(sorted_b[indx1]);
            indx1++;
        }
        else
        {
            sorted_a.push_back(sorted_c[indx2]);
            indx2++;
        }
    }
    return sorted_a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> ans = merge_sort(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << '\n';
}