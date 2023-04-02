

// Logic Bipartite Graph

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N];
int col[N];
bool ok;

void dfs(int u)
{
    vis[u] = true;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            if (col[u] == 1)
            {
                col[v] = 2;
            }
            else
            {
                col[v] = 1;
            }
            dfs(v);
        }
        else
        {
            if (col[u] == col[v])
            {
                ok = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ok = true;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            col[i] = 1;
            dfs(i);
        }
    }
    if (ok)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << col[i] << " ";
        }
        cout << '\n';
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}
