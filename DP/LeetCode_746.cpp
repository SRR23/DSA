#include <bits/stdc++.h>
using namespace std;
vector<int> v(1005);

class Solution
{
public:
    int mn_cost(vector<int> &cost, int n, vector<int> &dp)
    {
        if (n == 0)
        {
            return cost[0];
        }
        if (n == 1)
        {
            return cost[1];
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int ans1 = mn_cost(cost, n - 1, dp) + cost[n];
        int ans2 = mn_cost(cost, n - 2, dp) + cost[n];
        int mn = min(ans1, ans2);
        return dp[n] = mn;
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(mn_cost(cost, n - 1, dp), mn_cost(cost, n - 2, dp));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    Solution fun;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    cout << fun.minCostClimbingStairs(v) << '\n';
}