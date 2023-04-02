#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int n, m;
char s[N][N];
int vis[N][N];
int level[N][N];
int monster_lvl[N][N];
map<pair<int, int>, pair<int, int>> parnt;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_inside(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

bool is_safe(int i, int j)
{
    return (!vis[i][j] && s[i][j] == '.');
}

void bfs(int i, int j)
{
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> q;
    vis[i][j] = 1;

    q.push({i, j});

    while (!q.empty())
    {
        pair<int, int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;

        for (int k = 0; k < 4; k++)
        {
            int new_x = x + dx[k];
            int new_y = y + dy[k];

            if (is_inside(new_x, new_y) && is_safe(new_x, new_y))
            {
                vis[new_x][new_y] = 1;
                level[new_x][new_y] = level[x][y] + 1;
                parnt[{new_x, new_y}] = {x, y};
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

    int x1 = -1, y1 = -1;

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> s[i][j];

            if (s[i][j] == 'A')
            {
                x1 = i;
                y1 = j;
            }
            if (s[i][j] == 'M')
            {
                q.push({i, j});
            }
        }
    }
    if (x1 == 0 || x1 == n - 1 || y1 == 0 || y1 == m - 1)
    {
        cout << "YES" << '\n';
        cout << 0 << '\n';
        return 0;
    }

    while (!q.empty())
    {
        pair<int, int> head = q.front();
        int x = head.first;
        int y = head.second;
        q.pop();
        vis[x][y] = 1;
        for (int k = 0; k < 4; k++)
        {
            int a = x + dx[k];
            int b = y + dy[k];
            if (is_inside(a, b) && is_safe(a, b))
            {
                q.push({a, b});
                monster_lvl[a][b] = monster_lvl[x][y] + 1;
                vis[a][b] = 1;
            }
        }
    }

    bfs(x1, y1);

    bool fnd = 0;
    int x2 = -1, y2 = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && s[i][j] == '.')
            {
                if (!monster_lvl[i][j] && level[i][j])
                {
                    fnd = 1;
                    x2 = i;
                    y2 = j;
                }
                else if (monster_lvl[i][j] && level[i][j] && monster_lvl[i][j] > level[i][j])
                {
                    fnd = 1;
                    x2 = i;
                    y2 = j;
                    break;
                }
            }
        }
    }
    if (fnd)
    {
        cout << "YES" << '\n';
        cout << level[x2][y2] << '\n';
        string ans;
        while (x2 != x1 || y2 != y1)
        {
            int p = parnt[{x2, y2}].first;
            int q = parnt[{x2, y2}].second;

            if (p == x2 + 1)
            {
                ans.push_back('U');
            }
            if (p == x2 - 1)
            {
                ans.push_back('D');
            }
            if (q == y2 + 1)
            {
                ans.push_back('L');
            }
            if (q == y2 - 1)
            {
                ans.push_back('R');
            }
            x2 = p;
            y2 = q;
        }
        reverse(ans.begin(), ans.end());

        cout << ans << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }

    return 0;
}

// 5 8
// ########
// #M..A..#
// #.#.M#.#
// #M#..#..
// #.######
