
// You are given an integer n.You can perform any of the following
// operations on  it as many times you want:

// Subtract 1 from it
// If it is divisible by 2 divide by 2
// If it is divisible by 3 divide by 3

// Find the minimum number of operations to make n=1

// Memoization Method

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// int dp[N];

// int solve(int n)
// {
//     if (n == 1)
//     {
//         return 0;
//     }
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }
//     int x = INT_MAX, y = INT_MAX;
//     int z = solve(n - 1);
//     if (n % 2 == 0)
//     {
//         y = solve(n / 2);
//     }
//     if (n % 3 == 0)
//     {
//         x = solve(n / 3);
//     }

//     return dp[n] = min({x, y, z}) + 1;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int n;
//     cin >> n;
//     memset(dp, -1, sizeof(dp));
//     cout << solve(n) << '\n';
// }

// Tabulation Method

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    dp[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1];
        if (i % 2 == 0 && dp[i / 2] < dp[i])
        {
            dp[i] = dp[i / 2];
        }
        if (i % 3 == 0 && dp[i / 3] < dp[i])
        {
            dp[i] = dp[i / 3];
        }
        dp[i]++;
    }
    cout << dp[n] << '\n';
}
