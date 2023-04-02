// Find cycle in a Directed Graph and print cycle

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int colour[N];
bool f = 0;
int par[N];
vector<int> v;

void dfs(int node)
{
    colour[node] = 1;
    for (int i = 0; i < g[node].size(); i++)
    {
        int ch = g[node][i];
        if (!colour[ch])
        {
            colour[ch] = 1;
            par[ch] = node;
            dfs(ch);
        }
        else if (colour[ch] == 1 && !f)
        {
            int x = ch;
            v.push_back(ch);
            v.push_back(node);
            while (node != x)
            {
                node = par[node];
                v.push_back(node);
                f = 1;
            }
            reverse(v.begin(), v.end());
        }
    }
    colour[node] = 2;
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
    }

    for (int i = 1; i <= n; i++)
    {
        if (!colour[i] && !f)
        {
            dfs(i);
        }
    }

    if (f)
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