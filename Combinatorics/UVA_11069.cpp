#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll dp[77] = {0};
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= 76; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 3];
    }

    int n;
    while (cin >> n)
    {
        cout << dp[n] + dp[n - 1] << '\n';
    }
}