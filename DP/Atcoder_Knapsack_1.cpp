#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int w[N], v[N];
ll dp[105][N];
int n, m;

ll mx_sum(int n, int cap)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n][cap] != -1)
    {
        return dp[n][cap];
    }
    ll ans = mx_sum(n - 1, cap);
    if (cap - w[n] >= 0)
    {
        ans = max(ans, mx_sum(n - 1, cap - w[n]) + v[n]);
    }
    return dp[n][cap] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << mx_sum(n, m) << '\n';
}