
// Find cycle in an Undirected Graph and print cycle

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];
bool f = 0;
int par[N];
vector<int> v;

void dfs(int node, int p)
{
    vis[node] = 1;
    for (int i = 0; i < g[node].size(); i++)
    {
        int ch = g[node][i];
        if (!vis[ch])
        {
            vis[ch] = 1;
            par[ch] = node;
            dfs(ch, node);
        }
        else if (ch != p && !f)
        {
            int x = ch;
            f = 1;
            v.push_back(node);
            while (node != x)
            {
                node = par[node];
                if (node == 0)
                {
                    break;
                }
                v.push_back(node);
            }
            v.push_back(v[0]);
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
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && !f)
        {
            dfs(i, 0);
        }
    }

    if (f == true)
    {
        cout << v.size() << '\n';
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << '\n';
    }
    else
    {
        cout << "IMPOSSIBLE" << '\n';
    }
}