
// Count strongly connected components in directed graph
// print the lebel of componenets.

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;

int n, m;
int vis[N];
vector<int> g[N], g2[N], ext, v;
int lebel[N], cnt;

void dfs1(int u)
{
    vis[u] = 1;
    for (auto ch : g[u])
    {
        if (!vis[ch])
        {
            dfs1(ch);
        }
    }
    ext.push_back(u);
}

void dfs2(int u)
{
    vis[u] = 1;
    lebel[u] = cnt;
    for (auto ch : g2[u])
    {
        if (!vis[ch])
        {
            dfs2(ch);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g2[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs1(i);
        }
    }

    memset(vis, 0, sizeof(vis));
    cnt = 1;
    reverse(ext.begin(), ext.end());
    for (int i = 0; i < ext.size(); i++)
    {
        if (!vis[ext[i]])
        {
            dfs2(ext[i]);
            cnt++;
        }
    }
    cout << cnt - 1 << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << lebel[i] << " ";
    }
    cout << '\n';
}