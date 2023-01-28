#include <bits/stdc++.h>
using namespace std;
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
    for (int i = 1; i < n; i++)
    {
        int idx = i;
        while (idx >= 1)
        {
            if (v[idx - 1] > v[idx])
            {
                swap(v[idx - 1], v[idx]);
            }
            else
            {
                break;
            }
            idx--;
        }
        cout << "Considering " << i << ": ";
        for (int k = 0; k < n; k++)
        {
            cout << v[k] << " ";
        }
        cout << '\n';
    }
    cout << "After Sorting : ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << '\n';
}