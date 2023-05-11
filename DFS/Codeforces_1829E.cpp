#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int n, m;
int a[N][N];
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

    if (vis[i][j] || a[i][j] == 0)
    {
        return false;
    }
    return true;
}

int dfs(int i, int j)
{
    if (is_inside(i, j) && is_safe(i, j))
    {
        vis[i][j] = 1;
        int sum = a[i][j];
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            sum += dfs(x, y);
        }
        return sum;
    }
    return 0;
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
                cin >> a[i][j];
            }
        }

        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && a[i][j] > 0)
                {
                    mx = max(mx, dfs(i, j));
                }
            }
        }
        cout << mx << '\n';
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}