
// coin change varitation

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int dp[N];
int n, m;
int coin[105];

int mn_coin(int sum)
{
    if (sum == 0)
    {
        return 0;
    }
    if (dp[sum] != -1)
    {
        return dp[sum];
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        if (sum - coin[i] >= 0)
        {
            ans = min(ans + 0LL, 1LL + mn_coin(sum - coin[i]));
        }
    }

    return dp[sum] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> coin[i];
    }
    memset(dp, -1, sizeof(dp));
    if (mn_coin(m) == INT_MAX)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << mn_coin(m) << '\n';
    }
}