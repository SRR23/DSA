#include <bits/stdc++.h>
using namespace std;
vector<int> v(1005);

class Solution
{
public:
    int mx_cost(vector<int> &cost, int n, vector<int> &dp)
    {
        if (n < 0)
        {
            return 0;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }
        int ans1 = mx_cost(cost, n - 1, dp);
        int ans2 = mx_cost(cost, n - 2, dp) + cost[n];
        int mx = max(ans1, ans2);
        return dp[n] = mx;
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return mx_cost(nums, n - 1, dp);
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

    cout << fun.rob(v) << '\n';
}