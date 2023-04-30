
// Similar as Atcoder_Knapsack_1
// it is not Acceptable in Recursion approach due to tight time limit

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int price[N], page[N];
int dp[1005][N];
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> price[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> page[i];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
                if (j - price[i] >= 0)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i]] + page[i]);
                }
            }
        }
    }
    cout << dp[n][m] << '\n';
}