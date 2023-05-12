
// k node theke sobgula n nodes visit korte perbo kina,
// jodi pari, tahole minimum koto somoi lagbe
// sobgula n nodes visit korte.


#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<pair<int, int>>> g;
    vector<int> dist;

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        g.resize(n + 1);
        dist.resize(n + 1, 1e9);
        for (int i = 0; i < times.size(); i++)
        {
            g[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        dist[k] = 0;
        priority_queue<pair<int, int>> pq;
        pq.push({0, k});
        while (!pq.empty())
        {
            pair<int, int> head = pq.top();
            pq.pop();
            int selected_node = head.second;

            for (auto ch : g[selected_node])
            {
                int adj_node = ch.first;
                int edge_cst = ch.second;

                if (dist[selected_node] + edge_cst < dist[adj_node])
                {
                    dist[adj_node] = dist[selected_node] + edge_cst;
                    pq.push({-dist[adj_node], adj_node});
                }
            }
        }
        int mx = -1;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == 1e9)
            {
                return -1;
            }
            else
            {
                mx = max(mx, dist[i]);
            }
        }
        return mx;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < m; j++)
        {
            int val;
            cin >> val;
            tmp.push_back(val);
        }
        v.push_back(tmp);
    }

    int desti, src;
    cin >> desti >> src;

    Solution func;
    cout << func.networkDelayTime(v, desti, src) << '\n';
}