#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
int dp[N];

int cnt(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = 0;
    for (int i = 1; i <= 6; i++)
    {
        if (n - i >= 0)
        {
            ans += cnt(n - i);
            ans %= mod;
        }
    }
    return dp[n] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1;
    }
    cout << cnt(n) << '\n';
}