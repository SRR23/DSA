
// Memoization Method
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1 || n == 2)
        {
            return 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    int fib(int n)
    {
        vector<int> dp(n + 1, -1);
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

    cout << func.fib(n) << '\n';
}







// Tabulation Method

// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     int solve(int n, vector<int> &dp)
//     {
//         if (n < 2)
//         {
//             return n;
//         }
//         dp[0] = 0;
//         dp[1] = 1;
//         for (int i = 2; i <= n; i++)
//         {
//             dp[i] = dp[i - 1] + dp[i - 2];
//         }
//         return dp[n];
//     }

//     int fib(int n)
//     {
//         vector<int> dp(n + 1);
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

//     cout << func.fib(n) << '\n';
// }