#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[505][505];
int vis[505][505];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int p = 0, q = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> s[i][j];
        }
    }
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '*' && s[i - 1][j] == '*' && s[i + 1][j] == '*' &&
                s[i][j - 1] == '*' && s[i][j + 1] == '*')
            {
                for (int k = 0; k < 4; k++)
                {
                    int x = i;
                    int y = j;
                    while (1)
                    {
                        x += dx[k];
                        y += dy[k];
                        if (s[x][y] == '*')
                        {
                            p--;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                if (p == 1)
                {
                    f = 1;
                    break;
                }
            }
        }
    }
    if (f == 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
