#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[100][100];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
string str = "BW";

bool is_inside(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    return true;
}

void dfs(int i, int j, int indx)
{
    if (s[i][j] == '.' && is_inside(i, j))
    {
        s[i][j] = str[indx];
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            dfs(x, y, !(indx));
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '.')
            {
                dfs(i, j, 0);
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