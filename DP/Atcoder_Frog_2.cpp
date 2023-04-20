#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int h[N], dp[N];
int k;

int mn_cost(int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int mn = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (n - i > 0)
        {
            mn = min(mn, mn_cost(n - i) + abs(h[n] - h[n - i]));
        }
    }
    return dp[n] = mn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1;
    }
    cout << mn_cost(n) << '\n';
}