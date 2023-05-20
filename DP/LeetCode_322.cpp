
// same as CSES_MinimizingCoins
// Unbound Knapsack

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[10001];
    int solve(vector<int> &coins, int sum)
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
        for (auto it : coins)
        {
            if (sum - it >= 0)
            {
                ans = min(ans + 0LL, 1LL + solve(coins, sum - it));
            }
        }
        return dp[sum] = ans;
    }

    int coinChange(vector<int> &coins, int amount)
    {
        memset(dp, -1, sizeof(dp));

        if (solve(coins, amount) == INT_MAX)
        {
            return -1;
        }
        return solve(coins, amount);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Solution func;
    cout << func.coinChange(v, m) << '\n';
}