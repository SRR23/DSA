#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[55][55];

void dfs(int i, int j)
{
    if (s[i + 1][j] == '.' && i + 1 < n)
    {
        s[i + 1][j] = '*';
        s[i][j] = '.';
        dfs(i + 1, j);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> s[i][j];
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (s[i][j] == '*')
                {
                    dfs(i, j);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << s[i][j];
            }
            cout << '\n';
        }
    }
}