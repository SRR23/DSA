#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    dp[0] = 1;
    for (int j = 1; j <= m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (j - a[i] >= 0)
            {
                dp[j] += dp[j - a[i]];
                dp[j] %= mod;
            }
        }
    }
    cout << dp[m] << '\n';
}