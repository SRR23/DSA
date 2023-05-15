#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, int> dist;

ll bfs(int n, ll x)
{
    queue<ll> q;
    dist[x] = 0;
    q.push(x);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        string s = to_string(u);
        if (s.size() == n)
        {
            return dist[u];
        }
        for (auto it : s)
        {
            if (it == '0')
            {
                continue;
            }
            ll v = u * (it - '0');
            if (!dist.count(v))
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll x;
    cin >> n >> x;

    cout << bfs(n, x) << '\n';
}