#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int n, m;
char s[N][N];
int vis[N][N];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_inside(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
    {
        return true;
    }
    return false;
}

bool is_safe(int i, int j)
{

    if (vis[i][j] || s[i][j] == '#')
    {
        return false;
    }
    return true;
}

void dfs(int i, int j)
{
    if (is_inside(i, j) && is_safe(i, j))
    {
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            dfs(x, y);
        }
    }
}

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

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && s[i][j] == '.')
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}