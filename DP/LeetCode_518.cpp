
// Coin change variation
// similar as CSES_CoinCombinations_2

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (auto it : coins)
        {
            for (int j = 0; j <= amount; j++)
            {
                if (j - it >= 0)
                {
                    dp[j] += dp[j - it];
                }
            }
        }
        return dp[amount];
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
    cout << func.change(m, v) << '\n';
}