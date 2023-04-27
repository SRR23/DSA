
// Similar LeetCode_198, SPOJ_FARIDA

// Memoization Method

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

ll sum[N], dp[N];

ll mx_score(ll n)
{
    if (n == 1)
    {
        return sum[1];
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    ll ans1 = mx_score(n - 1);
    ll ans2 = mx_score(n - 2) + sum[n];
    ll mx = max(ans1, ans2);
    return dp[n] = mx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    ll a[n + 1];
    ll mx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[a[i]] += a[i];
        mx = max(mx, a[i]);
    }
    memset(dp, -1, sizeof(dp));

    cout << mx_score(mx) << '\n';
}


// Tabulation Method

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int N = 1e5 + 5;
 
// ll a[N], sum[N], dp[N];
 
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
 
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         sum[a[i]] += a[i];
//     }
 
//     dp[1] = sum[1];
//     for (int i = 2; i <= N; i++)
//     {
//         dp[i] = max(dp[i - 1], sum[i] + dp[i - 2]);
//     }
//     cout << dp[N] << '\n';
// }