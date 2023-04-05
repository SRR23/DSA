
// Your task is to find a minimum-price flight route from
// Syrjälä to Metsälä. You have one discount coupon, using which
// you can halve the price of any single flight during the route.
// However, you can only use the coupon once.

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

vector<pair<int, int>> g[N], g2[N];

int vis[N];
int n, m;

long long dis1[N], dis2[N];

void dijkstra_1(int src)
{
    for (int i = 1; i <= n; i++)
    {
        dis1[i] = INF;
    }
    dis1[src] = 0;

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

                if (dis1[selected_node] + edge_cst < dis1[adj_node])
                {
                    dis1[adj_node] = dis1[selected_node] + edge_cst;
                    pq.push({-dis1[adj_node], adj_node});
                }
            }
        }
    }
}

void dijkstra_2(int src)
{
    for (int i = 1; i <= n; i++)
    {
        dis2[i] = INF;
    }
    dis2[src] = 0;

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

            for (auto ch : g2[selected_node])
            {
                int adj_node = ch.first;
                int edge_cst = ch.second;

                if (dis2[selected_node] + edge_cst < dis2[adj_node])
                {
                    dis2[adj_node] = dis2[selected_node] + edge_cst;
                    pq.push({-dis2[adj_node], adj_node});
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

    cin >> n >> m;
    vector<tuple<int, int, int>> vec;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vec.push_back({u, v, w});
        g[u].push_back({v, w});
        g2[v].push_back({u, w});
    }

    dijkstra_1(1);
    memset(vis, 0, sizeof(vis));
    dijkstra_2(n);

    long long mn = INF;
    for (auto &&it : vec)
    {
        int u, v, w;
        tie(u, v, w) = it;
        mn = min(mn, dis1[u] + dis2[v] + w / 2);
    }
    cout << mn << '\n';
}