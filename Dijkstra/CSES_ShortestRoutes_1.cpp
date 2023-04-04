
// in a weighted directed graph
// print the shortest distance from node 1 to all nodes.

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

vector<pair<int, int>> g[N];

int vis[N], parent[N];
int nodes, edges;

long long d[N];

void dijkstra(int src)
{
    for (int i = 1; i <= nodes; i++)
    {
        d[i] = INF;
    }
    d[src] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {

        pair<long long, int> head = pq.top();
        pq.pop();
        int selected_node = head.second;

        if (!vis[selected_node])
        {
            vis[selected_node] = 1;

            for (auto ch : g[selected_node])
            {
                int adj_node = ch.first;
                int edge_cst = ch.second;

                if (d[selected_node] + edge_cst < d[adj_node])
                {
                    d[adj_node] = d[selected_node] + edge_cst;
                    parent[adj_node] = selected_node;
                    pq.push({-d[adj_node], adj_node});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    int src = 1;
    dijkstra(src);

    if (!vis[nodes])
    {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 1; i <= nodes; i++)
    {
        cout << d[i] << " ";
    }
    cout << '\n';
}