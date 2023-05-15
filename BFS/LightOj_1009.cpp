
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e4 + 5;
vector<int> g[N];
int vis[N];
ll color[N];

void clear()
{
    memset(vis, 0, sizeof(vis));
    memset(color, 0, sizeof(color));
    for (int i = 0; i <= N; i++)
    {
        g[i].clear();
    }
}

ll bfs(int n)
{
    ll lykn = 0, vampr = 0;
    queue<int> q;
    q.push(n);
    vis[n] = 1;
    color[n] = 1;
    vampr++;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto ch : g[u])
        {
            if (!vis[ch])
            {
                q.push(ch);
                vis[ch] = 1;
                if (color[u] == 1)
                {
                    color[ch] = 0;
                    lykn++;
                }
                else
                {
                    color[ch] = 1;
                    vampr++;
                }
            }
        }
    }

    return max(vampr + 0LL, lykn + 0LL);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        clear();
        cout << "Case " << k;
        int n;
        cin >> n;
        while (n--)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        ll sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (!vis[i] && !g[i].empty())
            {
                sum += bfs(i);
            }
        }
        cout << ": " << sum << '\n';
    }
}