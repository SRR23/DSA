#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

char s[N][N];
int n, m;
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

void bfs(int i, int j)
{

    queue<pair<int, int>> q;
    vis[i][j] = 1;

    q.push({i, j});

    while (!q.empty())
    {
        pair<int, int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (is_inside(new_x, new_y) && is_safe(new_x, new_y))
            {
                vis[new_x][new_y] = 1;
                q.push({new_x, new_y});
            }
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
                bfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}