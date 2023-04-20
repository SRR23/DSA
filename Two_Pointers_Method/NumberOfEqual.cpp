
// You are given two arrays a and b, sorted in non-decreasing order.
// Find the number of pairs (i,j) for which ai = bj.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    ll sum = 0;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            int p = a[i], x = 0, y = 0;
            while (i < n && a[i] == p)
            {
                x++;
                i++;
            }
            while (j < m && b[j] == p)
            {
                y++;
                j++;
            }
            sum += (1LL * x * y);
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << sum << '\n';
}

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     map<int, int> mp;
//     int n, m;
//     cin >> n >> m;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         mp[a[i]]++;
//     }
//     int b[m];
//     ll sum = 0;
//     for (int i = 0; i < m; i++)
//     {
//         cin >> b[i];
//         if (mp.count(b[i]))
//         {
//             sum += mp[b[i]];
//         }
//     }
//     cout << sum << '\n';
// }