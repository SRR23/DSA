#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int mod = 10000007;
int dp[N];
int a, b, c, d, e, f;

int fn(int n)
{
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    if (n == 2)
        return c;
    if (n == 3)
        return d;
    if (n == 4)
        return e;
    if (n == 5)
        return f;
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = 0;
    for (int i = 1; i <= 6; i++)
    {
        dp[n] += fn(n - i);
        dp[n] %= mod;
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        cout << "Case " << k;
        int n;
        cin >> a >> b >> c >> d >> e >> f >> n;
        memset(dp, -1, sizeof(dp));
        cout << ": " << fn(n) % mod << '\n';
    }
}