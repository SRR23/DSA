
// Print Single Source Shortest Path

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int vis[N];
int level[N];
int parent[N];

vector<int> g[N];
int n, m;

void bfs(int u)
{
    vis[u] = 1;
    level[u] = 1;
    parent[u] = -1;
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto ch : g[v])
        {
            if (!vis[ch])
            {
                vis[ch] = 1;
                level[ch] = level[v] + 1;
                parent[ch] = v;
                q.push(ch);
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
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(1);

    if (!vis[n])
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << level[n] << '\n';
        vector<int> path;
        int curr_node = n;
        while (1)
        {
            path.push_back(curr_node);
            if (curr_node == 1)
            {
                break;
            }
            curr_node = parent[curr_node];
        }
        reverse(path.begin(), path.end());
        for (auto it : path)
        {
            cout << it << " ";
        }
        cout << '\n';
    }
}