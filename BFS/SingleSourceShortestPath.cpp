#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

bool visited[N];
int level[N];

vector<int> g[N];

void bfs(int src)
{
    queue<int> q;

    visited[src] = 1;
    level[src] = 0;
    q.push(src);

    while (!q.empty())
    {
        int head = q.front();
        q.pop();

        for (int ch : g[head])
        {
            if (!visited[ch])
            {
                visited[ch] = 1;

                level[ch] = level[head] + 1;

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

    g[0].push_back(1);
    g[1].push_back(0);

    g[0].push_back(3);
    g[3].push_back(0);

    g[0].push_back(4);
    g[4].push_back(0);

    g[1].push_back(5);
    g[5].push_back(1);

    g[1].push_back(2);
    g[2].push_back(1);

    g[2].push_back(4);
    g[4].push_back(2);

    g[5].push_back(4);
    g[4].push_back(5);

    bfs(0);

    for (int i = 0; i < 6; i++)
    {
        cout << "node " << i << " -> level: " << level[i] << '\n';
    }
    return 0;
}
