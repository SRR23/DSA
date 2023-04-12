
// All Pair Shortest Path.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
const ll INF = 1e18;
ll dis[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = INF;
        }
    }
    while (m--)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
    }

    for (int i = 1; i <= n; i++)
    {
        dis[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= n; v++)
            {
                dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
            }
        }
    }

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (dis[u][v] == INF)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << dis[u][v] << '\n';
        }
    }
}