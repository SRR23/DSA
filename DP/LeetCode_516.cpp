
// Longest Palindromic Subsequence

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n, m;
    string b;
    int dp[1003][1003];
    int LCS(int i, int j, string &a)
    {
        if (i == n || j == m)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (a[i] == b[j])
        {
            int ans = 1 + LCS(i + 1, j + 1, a);
            return dp[i][j] = ans;
        }
        int ans = max(LCS(i + 1, j, a), LCS(i, j + 1, a));
        return dp[i][j] = ans;
    }

    int longestPalindromeSubseq(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            b.push_back(s[i]);
        }
        reverse(b.begin(), b.end());
        n = s.size();
        m = b.size();
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                dp[i][j] = -1;
            }
        }
        return LCS(0, 0, s);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    Solution func;
    cout << func.longestPalindromeSubseq(s) << '\n';
}