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

    int j = 0, k = 0;
    vector<int> v;
    for (int i = 0; i < n + m; i++)
    {
        if (j == n)
        {
            v.push_back(b[k]);
            k++;
        }
        else if (k == m)
        {
            v.push_back(a[j]);
            j++;
        }
        else if (a[j] < b[k])
        {
            v.push_back(a[j]);
            j++;
        }
        else
        {
            v.push_back(b[k]);
            k++;
        }
    }
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << '\n';
}