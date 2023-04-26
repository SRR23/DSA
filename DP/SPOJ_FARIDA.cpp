
// Same as LeetCode_198

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        cout << "Case " << k << ": ";

        ll n;
        cin >> n;
        vector<ll> v(n + 1), dp(n + 3, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }

        for (int i = n; i >= 1; i--)
        {
            dp[i] = max(dp[i + 1], v[i] + dp[i + 2]);
        }
        cout << dp[1] << '\n';
    }
}

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// ll mx_cost(vector<ll> &cost, ll n, vector<ll> &dp)
// {
//     if (n < 0)
//     {
//         return 0;
//     }

//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }
//     ll ans1 = mx_cost(cost, n - 1, dp);
//     ll ans2 = mx_cost(cost, n - 2, dp) + cost[n];
//     ll mx = max(ans1, ans2);
//     return dp[n] = mx;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int t;
//     cin >> t;
//     for (int k = 1; k <= t; k++)
//     {
//         cout << "Case " << k << ": ";
//         ll n;
//         cin >> n;
//         vector<ll> a(n + 1), dp(n + 1, -1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin >> a[i];
//         }

//         cout << mx_cost(a, n, dp) << '\n';
//     }
// }