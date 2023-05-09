
// Knapsack variation

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        if (sum & 1)
        {
            return false;
        }

        int total = sum / 2;

        int dp[n + 1][total + 1];
        dp[0][0] = true;
        for (int i = 1; i <= total; i++)
        {
            dp[0][i] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= total; j++)
            {
                int ans1 = dp[i - 1][j];
                if (j < nums[i])
                {
                    dp[i][j] = ans1;
                }
                else
                {
                    int ans2 = dp[i - 1][j - nums[i]];
                    dp[i][j] = ans1 or ans2;
                }
            }
        }
        return dp[n][total];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    Solution func;
    cout << func.canPartition(v) << '\n';
}