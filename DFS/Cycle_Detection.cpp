#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
int col[N], par[N];
bool cycle;

void dfs(int u)
{
    col[u] = 1;
    for (auto v : g[u])
    {
        if (col[v] == 0)
        {
            par[v] = u;
            dfs(v);
        }
        else if (col[v] == 1)
        {
            cycle = true;
        }
    }
    col[u] = 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (col[i] == 0)
        {
            dfs(i);
        }
    }
    cout << (cycle ? "YES\n" : "NO\n") << '\n';
    return 0;
}