
// You play a game consisting of n rooms and m tunnels.
// Your initial score is 0, and each tunnel increases your score
// by x where x may be both positive or negative. You may go
// through a tunnel several times.

// Your task is to walk from room 1 to room n. What is the
// maximum score you can get?

#include <bits/stdc++.h>
using namespace std;

const int N = 2500 + 5;
const long long INF = 1e16;

vector<int> g[N], g2[N];

int vis1[N], vis2[N];
int n, m;

long long dis[N];

void dfs1(int u)
{
    vis1[u] = 1;
    for (auto ch : g[u])
    {
        if (!vis1[ch])
        {
            dfs1(ch);
        }
    }
}

void dfs2(int u)
{
    vis2[u] = 1;
    for (auto ch : g2[u])
    {
        if (!vis2[ch])
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
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    dis[1] = 0;
    vector<tuple<int, int, int>> vec;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vec.push_back({u, v, -w});
        g[u].push_back(v);
        g2[v].push_back(u);
    }
    dfs1(1);
    dfs2(n);

    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        for (auto it : vec)
        {
            int u, v, w;
            tie(u, v, w) = it;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (i == n - 1 && vis1[v] && vis2[v])
                {
                    ok = false;
                    break;
                }
            }
        }
    }
    if (ok)
    {
        cout << -dis[n] << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
}
