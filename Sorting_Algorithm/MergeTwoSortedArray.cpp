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
    int indx1 = 0, indx2 = 0;
    vector<int> v;
    for (int i = 0; i < n + m; i++)
    {
        if (indx1 == n)
        {
            v.push_back(b[indx2]);
            indx2++;
        }
        else if (indx2 == m)
        {
            v.push_back(a[indx1]);
            indx1++;
        }
        else if (a[indx1] < b[indx2])
        {
            v.push_back(a[indx1]);
            indx1++;
        }
        else
        {
            v.push_back(b[indx2]);
            indx2++;
        }
    }

    for (int i = 0; i < n + m; i++)
    {
        cout << v[i] << " ";
    }
    cout << '\n';
}