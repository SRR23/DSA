
// Degree

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, ans = 0;
    int table[101][101], num[101];
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            table[i][j] = 0;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        table[a][b] = 1;
        table[b][a] = 1;
        num[a]++;
        num[b]++;
    }
    while (1)
    {
        int key = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (num[i] == 1)
            {
                key = 1;
                for (int j = 1; j <= n; ++j)
                {
                    table[i][j] = 0;
                    table[j][i] = 0;
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            num[i] = 0;
            for (int j = 1; j <= n; ++j)
            {
                num[i] += table[i][j];
            }
        }
        if (key)
            ans++;
        else
            break;
    }
    cout << ans;
}