

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> deg(n + 1);
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            deg[u]++;
            deg[v]++;
        }

        int one = count(deg.begin(), deg.end(), 1);
        cout << n - 1 - one << " " << one / (n - 1 - one) << '\n';
    }
}