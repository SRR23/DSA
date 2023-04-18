#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int h[N], dp[N];

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

    int ans1 = mn_cost(n - 1) + abs(h[n] - h[n - 1]);
    if (n == 2)
    {
        dp[n] = ans1;
        return ans1;
    }
    int ans2 = mn_cost(n - 2) + abs(h[n] - h[n - 2]);

    return dp[n] = min(ans1, ans2);
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
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1;
    }
    cout << mn_cost(n) << '\n';
}