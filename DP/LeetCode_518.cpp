#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[10001];
    int solve(int n, vector<int> &coins, int sum)
    {
        if (sum == 0)
        {
            return 1;
        }
        if (dp[sum] != -1)
        {
            return dp[sum];
        }
        int ans = solve(n - 1, coins, sum);
        for (auto it : coins)
        {
            if (sum - it >= 0)
            {
                ans += solve(n, coins, sum - it);
            }
        }
        return dp[sum] = ans;
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));

        // if (solve(coins, amount) == 0)
        // {
        //     return 0;
        // }
        return solve(n - 1, coins, amount);
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