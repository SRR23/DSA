
// Memoization Method

// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     int solve(int n, vector<int> &dp)
//     {
//         if (n == 0)
//         {
//             return 0;
//         }
//         if (n == 1 || n == 2)
//         {
//             return 1;
//         }
//         if (dp[n] != -1)
//         {
//             return dp[n];
//         }
//         return dp[n] = solve(n - 1, dp) + solve(n - 2, dp) + solve(n - 3, dp);
//     }
//     int tribonacci(int n)
//     {
//         vector<int> dp(n + 1, -1);
//         return solve(n, dp);
//     }
// };

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int n;
//     cin >> n;
//     Solution func;
//     cout << func.tribonacci(n) << '\n';
// }


// Tabulation Method

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        if (n < 2)
        {
            return n;
        }
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
    int tribonacci(int n)
    {
        vector<int> dp(n + 1);
        return solve(n, dp);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    Solution func;
    cout << func.tribonacci(n) << '\n';
}
