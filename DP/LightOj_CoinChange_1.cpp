
// Coin change variation

#include <bits/stdc++.h>
using namespace std;
const int mod = 100000007;
vector<int> coin(51), limit(51);
int dp[51][1001];

int solve(int n, int sum)
{
    if (n == 0)
    {
        if (sum == 0)
        {
            return 1;
        }
        return 0;
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    int ans = solve(n - 1, sum);
    for (int i = 1; i <= limit[n]; i++)
    {
        if (sum - (i * coin[n]) >= 0)
        {
            ans += solve(n-1, sum - (i * coin[n]));
        }
    }
    return dp[n][sum] = ans % mod;
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
        cout << "Case " << k << ":";
        int n, m;
        cin >> n >> m;
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            cin >> coin[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> limit[i];
        }
        cout << " " << solve(n, m) << '\n';
    }
}