
// Connected components

#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[101][101];
bool vis[101][101];
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool is_inside(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    return true;
}

void dfs(int i, int j)
{
    vis[i][j] = 1;
    for (int k = 0; k < 8; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (s[x][y] == '@' && !vis[x][y] && is_inside(x, y))
        {
            vis[x][y] = 1;
            dfs(x, y);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        memset(vis, 0, sizeof(vis));
        cin >> n >> m;
        if (m == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> s[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (s[i][j] == '@' && !vis[i][j])
                {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}