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
    for (int i = 0; i < n; i++)
    {
        int last = n - 1 - i;
        for (int j = 0; j <= last - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
        cout << "After pass " << i << ": ";
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